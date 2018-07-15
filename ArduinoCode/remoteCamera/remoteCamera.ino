/* Remote camera control
   Author: Dang Ba Phong
   Created: 09/06/2018
   email: phong12a5@gmail.com
*/

#include <Ethernet.h>
#include "PubSubClient.h"

#define CLIENT_ID                       "100"
#define MQTT_HOST                       "m12.cloudmqtt.com"
#define MQTT_USER                       "fgnqzkic"
#define MQTT_PASSWD                     "zDISWheFKSN5"
#define MQTT_PORT                       19044

#define PUB_TOPIC_DISCONECTED           "DISCONECTED"
#define PUB_TOPIC_CONNECTED             "CONNECTED"
#define PUB_TOPIC_RESP_DATA             "CAMERA_00_RESP"

#define SUB_TOPIC_INIT_DATA             "REQUESTDATA"
#define SUB_TOPIC_REQ_CHANGE_POS        "CAMERA_00_REQ"

#define INPUT_SIZE                      10

#define PIN_MOVING_DOWN                 A0
#define PIN_MOVING_UP                   A1

#define LOG(a)                          //Serial.print(a)
#define LOG_LN(a)                       //Serial.println(a)

enum E_MOVING_STATUS: int{
    E_MOVING_NONE = 0,
    E_MOVING_UP,
    E_MOVING_DOWN,
};

String ip = "";
uint8_t mac[6] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
long previousMillis = 0;
unsigned int requestedPosition = -1;
int lastActivePos = -1;
int isMoving = (int)E_MOVING_STATUS::E_MOVING_NONE;
EthernetClient ethClient;
PubSubClient mqttClient;

unsigned int pos_pin[INPUT_SIZE] = {0,1,2,3,4,5,6,7,8,9};
char trans_data[INPUT_SIZE] = {'0','1','2','3','4','5','6','7','8','9'};

void initProgram();
int getActivedPin();
void movingToPosition(int pos);
void responseActivedPosToDevice(int pos);
void sendDataToBroker(const char* topic, const char* data, bool retained = false);
void connectToBroker();
void callback(char* topic, byte* payload, unsigned int length);
void movingUp();
void movingDown();
void stopMoving();

void setup() {
    delay(1000);
    LOG_LN(">>> Welcome to MQTT Arduino Project <<<");
    // setup serial communication
//    Serial.begin(9600);
//    while (!Serial) {};
    LOG_LN(">>> Setup PIN <<<");
    for(int i = 0; i < INPUT_SIZE; i++){
        pinMode(pos_pin[i], INPUT_PULLUP);
    }

    pinMode(PIN_MOVING_UP, OUTPUT);
    pinMode(PIN_MOVING_DOWN, OUTPUT);
    digitalWrite(PIN_MOVING_DOWN,LOW);
    digitalWrite(PIN_MOVING_UP,LOW);

    // setup ethernet communication using DHCP
    if (Ethernet.begin(mac) == 0) {
        LOG_LN(">>> Unable to configure Ethernet using DHCP <<< ");
        for (;;);
    }

    LOG(">>> Ethernet configured via DHCP <<<");
    LOG_LN(">>> IP address: ");
    LOG(Ethernet.localIP());
    LOG_LN(" <<<");

    // setup mqtt client
    mqttClient.setClient(ethClient);
    mqttClient.setServer(MQTT_HOST, MQTT_PORT);
    mqttClient.setCallback(callback);
    connectToBroker();
    LOG_LN(">>> Connected <<<");

    // Init Application
    initProgram();
}

void loop() {
    int activedPos = getActivedPin();
    if (isMoving == E_MOVING_STATUS::E_MOVING_UP ||
            isMoving == E_MOVING_STATUS::E_MOVING_DOWN){
        if (requestedPosition == activedPos){
            stopMoving();
        }
    } else {
        if (requestedPosition != activedPos){
            requestedPosition = activedPos;
        }
    }

    if(lastActivePos != activedPos){
        responseActivedPosToDevice(-1);
        lastActivePos = activedPos;
    }

    if (!mqttClient.connected())
    {
        connectToBroker();
    }
    mqttClient.loop();
}

void initProgram() {
    LOG_LN(">>> Init Application <<<");
    int actviedPos = getActivedPin();
    sendDataToBroker(static_cast<const char *>(PUB_TOPIC_CONNECTED), static_cast<const char *>(CLIENT_ID), false);
    if (actviedPos >= pos_pin[0] && actviedPos <= pos_pin[INPUT_SIZE - 1])
    {
        responseActivedPosToDevice(actviedPos);
    }
}

int getActivedPin()
{
    int count = 0;
    int activedPos = -1;
    for(int i = 0; i < INPUT_SIZE; ++i){
        if (!digitalRead(pos_pin[i]))
        {
            count ++;
            activedPos = pos_pin[i];
        }
    }

    if (count > 1)
    {
        activedPos = -1;
    } else if (count <= 0)
    {
        activedPos = -1;
    }
    return activedPos;
}

void responseActivedPosToDevice(int pos)
{
    LOG_LN(">>> responseActivedPosToDevice <<<");
    int actviedPos = getActivedPin();
    if (actviedPos >= pos_pin[0] && actviedPos <= pos_pin[INPUT_SIZE - 1])
    {
        for(int i = 0; i < INPUT_SIZE; ++i){
            if(actviedPos == pos_pin[i]){
                char data_str[2];
                data_str[0] = trans_data[i];
                data_str[1] = '\0';
                sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),data_str, true);
                break;
            }
        }
    }else if(pos == -1){
        sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),"-1", true);
    }
}

void sendDataToBroker(const char* topic, const  char* data, bool retained)
{
    if (topic != nullptr && data != nullptr)
    {
        LOG(">>> sendDataToBroker >>> topic: ");
        LOG(topic);
        LOG(" >>> data: ");
        LOG(data);
        LOG_LN(" <<<");
        mqttClient.publish(topic, data, retained);
    }
    else
    {
        LOG(">>> sendDataToBroker : Data is invalid <<<");
    }
}

void connectToBroker()
{
  
    while (!mqttClient.connected())
    {
        LOG_LN(">>> Waiting for connect to Broker <<<");
        delay(500);
        mqttClient.connect(CLIENT_ID, MQTT_USER, MQTT_PASSWD, PUB_TOPIC_DISCONECTED, MQTTQOS1, true, CLIENT_ID);
    }
    mqttClient.subscribe(SUB_TOPIC_INIT_DATA);
    mqttClient.subscribe(SUB_TOPIC_REQ_CHANGE_POS);
}

void callback(char* topic, byte* payload, unsigned int length) {
    LOG(">>> Message arrived [");
    LOG(topic);
    LOG("] <<<");//MQTT_BROKER
    if (length > 0)
    {
        if (strcmp(topic, static_cast<const char*>(SUB_TOPIC_REQ_CHANGE_POS)) == 0)
        {
            if(isMoving == (int)E_MOVING_STATUS::E_MOVING_UP ||
                    isMoving == (int)E_MOVING_STATUS::E_MOVING_DOWN){
                return;
            }

            for(int i = 0; i < INPUT_SIZE; ++i){
                if(trans_data[i] == payload[0]){
                    LOG_LN(">>> Requested position: ");
                    LOG(trans_data[i]);
                    LOG_LN(" <<<");
                    movingToPosition(pos_pin[i]);
                    requestedPosition = pos_pin[i];
                    break;
                }
            }
        }
        else if (strcmp(topic, static_cast<const char*>(SUB_TOPIC_INIT_DATA)) == 0)
        {
            int activedPos = getActivedPin();
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_CONNECTED), static_cast<const char *>(CLIENT_ID), false);
            if (activedPos >= pos_pin[0] && activedPos <= pos_pin[INPUT_SIZE - 1])
            {
                responseActivedPosToDevice(activedPos);
            }
        }
    }
}

void movingToPosition(int pos)
{
    int activedPos = getActivedPin();
    if (activedPos >= pos_pin[0] && activedPos <= pos_pin[INPUT_SIZE - 1] && pos >= pos_pin[0] && pos <= pos_pin[INPUT_SIZE - 1])
    {
        if (activedPos == pos)
        {
            LOG_LN("Requested position is already actived!");
            return;
        }else if(pos < activedPos){
            movingDown();
        }else{
            movingUp();
        }
    }
}

void movingUp() {
    LOG_LN(">>> Moving up <<<");
    digitalWrite(PIN_MOVING_DOWN, LOW);
    digitalWrite(PIN_MOVING_UP, HIGH);
    isMoving = (int)E_MOVING_STATUS::E_MOVING_UP;
}
void movingDown() {
    LOG_LN(">>> Moving down <<<");
    digitalWrite(PIN_MOVING_UP, LOW);
    digitalWrite(PIN_MOVING_DOWN, HIGH);
    isMoving = (int)E_MOVING_STATUS::E_MOVING_DOWN;
}
void stopMoving() {
    LOG_LN(">>> Stopped moving<<<");
    digitalWrite(PIN_MOVING_UP, LOW);
    digitalWrite(PIN_MOVING_DOWN, LOW);
    isMoving = (int)E_MOVING_STATUS::E_MOVING_NONE;
}
