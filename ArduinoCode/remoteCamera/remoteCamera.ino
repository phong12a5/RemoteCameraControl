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

#define DATA_POS_0                      "0"
#define DATA_POS_1                      "1"
#define DATA_POS_2                      "2"
#define DATA_POS_3                      "3"
#define DATA_POS_4                      "4"

#define PIN_POS_0                       5
#define PIN_POS_1                       6
#define PIN_POS_2                       7
#define PIN_POS_3                       8
#define PIN_POS_4                       9

#define PIN_MOVING_DOWN                 2
#define PIN_MOVING_UP                   3

#define READPIN_DELAY_TIMEOUT           30
#define LOG(a)                          Serial.print(a)
#define LOG_LN(a)                       Serial.println(a)

String ip = "";
uint8_t mac[6] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
long previousMillis = 0;
unsigned int requestedPosition = -1;
bool isMoving = false;
EthernetClient ethClient;
PubSubClient mqttClient;

void initProgram();
int getActivedPin();
void movingToPosition(int pos);
void responseActivedPosToDevice(int pos);
void sendDataToBroker(const char* topic,const char* data, bool retained = false);
void connectToBroker();
void callback(char* topic, byte* payload, unsigned int length);
void movingUp();
void movingDown();
void stopMoving();

void setup() {
    LOG_LN(">>> Welcome to MQTT Arduino Project <<<");
    // setup serial communication
    Serial.begin(9600);
    while (!Serial) {};
    LOG_LN(">>> Setup PIN <<<");
    pinMode(PIN_POS_0,INPUT_PULLUP);
    pinMode(PIN_POS_1,INPUT_PULLUP);
    pinMode(PIN_POS_2,INPUT_PULLUP);
    pinMode(PIN_POS_3,INPUT_PULLUP);
    pinMode(PIN_POS_4,INPUT_PULLUP);
    pinMode(PIN_MOVING_DOWN,OUTPUT);
    pinMode(PIN_MOVING_DOWN,OUTPUT);

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
    //  if (millis() - previousMillis > PUBLISH_DELAY) {
    //    previousMillis = millis();
    //
    //  }
    int activedPos = getActivedPin();
    if(isMoving)
    {
        if(requestedPosition == activedPos)
        {
            stopMoving();
        }
    }else{
        if(requestedPosition >= 0 && requestedPosition != activedPos)
        {
            movingToPosition(requestedPosition);
        }
    }

    if(!mqttClient.connected())
    {
        connectToBroker();
    }
    mqttClient.loop();
}

void initProgram(){
    LOG_LN(">>> Init Application <<<");
    int actviedPos = getActivedPin();
    sendDataToBroker(static_cast<const char *>(PUB_TOPIC_CONNECTED),static_cast<const char *>(CLIENT_ID),false);
    if(actviedPos >= PIN_POS_0 && actviedPos <= PIN_POS_4)
    {
        responseActivedPosToDevice(actviedPos);
    }
}

int getActivedPin()
{
    int count = 0;
    int activedPos = -1;
    if(!digitalRead(PIN_POS_0))
    {
        count ++;
        activedPos = PIN_POS_0;
    }
    if(!digitalRead(PIN_POS_1))
    {
        count ++;
        activedPos = PIN_POS_1;
    }
    if(!digitalRead(PIN_POS_2))
    {
        count ++;
        activedPos = PIN_POS_2;
    }
    if(!digitalRead(PIN_POS_3))
    {
        count ++;
        activedPos = PIN_POS_3;
    }
    if(!digitalRead(PIN_POS_4))
    {
        count ++;
        activedPos = PIN_POS_4;
    }

    if(count > 1)
    {
        LOG_LN(">>> Have more 1 Actived pos! <<<");
        activedPos = -1;
    }else if(count <= 0)
    {
        LOG_LN(">>> There isn't any actived position! <<<");
        activedPos = -1;
    }
    return activedPos;
}

void responseActivedPosToDevice(int pos)
{
    LOG_LN(">>> responseActivedPosToDevice <<<");
    int actviedPos = getActivedPin();
    if(actviedPos >= PIN_POS_0 && actviedPos <= PIN_POS_4)
    {
        switch (actviedPos) {
        case PIN_POS_0:
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),static_cast<const char *>(DATA_POS_0), true);
            break;
        case PIN_POS_1:
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),static_cast<const char *>(DATA_POS_1), true);
            break;
        case PIN_POS_2:
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),static_cast<const char *>(DATA_POS_2), true);
            break;
        case PIN_POS_3:
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),static_cast<const char *>(DATA_POS_3), true);
            break;
        case PIN_POS_4:
            sendDataToBroker(static_cast<const char *>(PUB_TOPIC_RESP_DATA),static_cast<const char *>(DATA_POS_4), true);
            break;
        default:
            break;
        }
    }
}

void sendDataToBroker(const char* topic,const  char* data, bool retained)
{
    if(topic != nullptr && data != nullptr)
    {
        LOG(">>> sendDataToBroker >>> topic: ");
        LOG(topic);
        LOG(" >>> data: ");
        LOG(data);
        LOG_LN(" <<<");
        mqttClient.publish(topic,data,retained);
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
    if(length>0)
    {
        if(strcmp(topic,static_cast<const char*>(SUB_TOPIC_REQ_CHANGE_POS)) == 0)
        {
            if(payload[0] == '0')
            {
                LOG_LN(">>> Requested position: ");
                LOG(DATA_POS_0);
                LOG_LN(" <<<");
                movingToPosition(PIN_POS_0);
                requestedPosition = PIN_POS_0;
            }else if(payload[0] == '1')
            {
                LOG_LN(">>> Requested position: ");
                LOG(DATA_POS_1);
                LOG_LN(" <<<");
                movingToPosition(PIN_POS_1);
                requestedPosition = PIN_POS_1;
            }
            else if(payload[0] == '2')
            {
                LOG_LN(">>> Requested position: ");
                LOG(DATA_POS_2);
                LOG_LN(" <<<");
                movingToPosition(PIN_POS_2);
                requestedPosition = PIN_POS_2;
            }
            else if(payload[0] == '3')
            {
                LOG_LN(">>> Requested position: ");
                LOG(DATA_POS_3);
                LOG_LN(" <<<");
                movingToPosition(PIN_POS_3);
                requestedPosition = PIN_POS_3;
            }
            else if(payload[0] == '4')
            {
                LOG_LN(">>> Requested position: ");
                LOG(DATA_POS_4);
                LOG_LN(" <<<");
                movingToPosition(PIN_POS_4);
                requestedPosition = PIN_POS_4;
            }
        }
        else if(strcmp(topic,static_cast<const char*>(SUB_TOPIC_INIT_DATA)) == 0)
        {
            int activedPos = getActivedPin();
            if(activedPos >= PIN_POS_0 && activedPos <= PIN_POS_4)
            {
                responseActivedPosToDevice(activedPos);
            }
        }
    }
}

void movingToPosition(int pos)
{
    int activedPos = getActivedPin();
    if(activedPos >= PIN_POS_0 && activedPos <= PIN_POS_4 && pos >= PIN_POS_0 && pos <= PIN_POS_4)
    {
        if(activedPos == pos)
        {
            LOG_LN("Requested position is already actived!");
            return;
        }
        switch (activedPos) {
        case PIN_POS_0:
            movingUp();
            break;
        case PIN_POS_1:
            if(pos == PIN_POS_0) movingDown();
            else movingUp();
            break;
        case PIN_POS_2:
            if(pos < PIN_POS_2) movingDown();
            else movingUp();
            break;
        case PIN_POS_3:
            if(pos == PIN_POS_4) movingUp();
            else movingDown();
            break;
        case PIN_POS_4:
            movingDown();
            break;
        }
    }
}

void movingUp(){
    LOG_LN(">>> Moving up <<<");
    digitalWrite(PIN_MOVING_DOWN,LOW);
    digitalWrite(PIN_MOVING_UP,HIGH);
    isMoving = true;
}
void movingDown(){
    LOG_LN(">>> Moving down <<<");
    digitalWrite(PIN_MOVING_UP,LOW);
    digitalWrite(PIN_MOVING_DOWN,HIGH);
    isMoving = true;
}
void stopMoving(){
    LOG_LN(">>> Stopped moving<<<");
    digitalWrite(PIN_MOVING_UP,LOW);
    digitalWrite(PIN_MOVING_DOWN,LOW);
    isMoving = false;
}
