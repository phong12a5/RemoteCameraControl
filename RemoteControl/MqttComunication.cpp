#include "MqttComunication.h"
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QMqttClient>
#include "MyModel.h"

#define MODEL MyModel::getInstance()

MqttComunication::MqttComunication(QObject *parent) : QObject(parent)
{
    m_client = new QMqttClient(this);
    m_countPingRequest = 0;
    m_timerPing.setInterval(PING_TIMEOUT);
    m_timerPing.setSingleShot(false);
    connect(&m_timerPing, SIGNAL(timeout()), this, SLOT(requestPing()));
}

void MqttComunication::initClient()
{
    DLT_LOG << "[initClient]";
    m_client->setHostname(QString(MQTT_HOST));
    m_client->setUsername(QString(MQTT_USER));
    m_client->setPassword(QString(MQTT_PASSWD));
    m_client->setPort(MQTT_PORT);
    m_client->cleanSession();
    connect(m_client, SIGNAL(connected()), this, SLOT(slotBrokerConnected()));
    connect(m_client, SIGNAL(disconnected()), this, SLOT(slotBrokerDisconnected()));
    connect(m_client, SIGNAL(messageReceived(const QByteArray, const QMqttTopicName)), this, SLOT(receivedMessage(const QByteArray, const QMqttTopicName)));
    connect(m_client, SIGNAL(pingResponseReceived()), this, SLOT(slotPingResponse()));
    connectBroker();
    registerSubcrible();
    m_timerPing.start();
}

void MqttComunication::registerSubcrible()
{
    DLT_LOG << "[registerSubcrible]";
    QList<CAMERA_ID> _keyList = TABLE_CAMERA.keys();
    for(int i = 0; i < _keyList.count(); i++){
        m_client->subscribe(TABLE_CAMERA.value(_keyList[i]).m_subTopic);
    }

    m_client->subscribe(QString(DISCONECTED_TOPIC));
     m_client->subscribe(QString(CONNECTED_TOPIC));
}

void MqttComunication::connectBroker()
{
    DLT_LOG << "[connectBroker]";
    m_client->connectToHost();
}

bool MqttComunication::getConnectStatus()
{
    return m_client->state() == QMqttClient::Connected;
}

void MqttComunication::slotBrokerConnected()
{
    if(m_client->state() == QMqttClient::Connected)
    {
        DLT_LOG << "[slotBrokerConnected] "<< "connected";
        MODEL->setConnectedServer(true);
        registerSubcrible();
    }
}

void MqttComunication::slotBrokerDisconnected()
{
    if(m_client->state() == QMqttClient::Disconnected || m_client->state() == QMqttClient::Connecting)
    {
        DLT_LOG << "[slotBrokerDisconnected] " << "Waiting for connect again!";
        MODEL->setConnectedServer(false);
        m_client->connectToHost();
    }
}

void MqttComunication::receivedMessage(const QByteArray &message, const QMqttTopicName &topic)
{
    DLT_LOG << "[receivedMessage]";
    emit receivedRespone(topic.name(),message);
}

void MqttComunication::slotPublishData(QString topicName, int data)
{
    DLT_LOG << "[slotPublishData] >> topicName: " << topicName << " >> Data: " << data;
    if(m_client->state() == QMqttClient::Connected)
    {
        m_client->publish(topicName,QByteArray::number(data));
    }
}

void MqttComunication::slotPingResponse()
{
    m_countPingRequest = 0;
    MODEL->setConnectedServer(true);
    MODEL->setShowPopupCheckConn(false);
}

void MqttComunication::requestPing()
{
    m_client->requestPing();
    if(m_countPingRequest >= 3)
    {
        DLT_LOG << "[requestPing] >> Show Popup";
        MODEL->setConnectedServer(false);
        MODEL->setShowPopupCheckConn(true);
        connectBroker();
    }
    m_countPingRequest ++;
}

