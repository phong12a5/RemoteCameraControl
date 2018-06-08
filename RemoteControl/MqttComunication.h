#ifndef MQTTCOMUNICATION_H
#define MQTTCOMUNICATION_H

#include <QObject>
#include <QMqttClient>
#include <AppDefine.h>
#include <QTimer>

class MqttComunication : public QObject
{
    Q_OBJECT
public:
    explicit MqttComunication(QObject *parent = nullptr);

    void initClient();
    void registerSubcrible();
    void connectBroker();
    bool getConnectStatus();

private:
    QMqttClient *m_client;
    QTimer m_timerPing;
    int m_countPingRequest;

public slots:
    void slotBrokerConnected();
    void slotBrokerDisconnected();
    void receivedMessage(const QByteArray &message, const QMqttTopicName &topic);
    void slotPublishData(QString topicName, int data);
    void slotPingResponse();
    void requestPing();

signals:
    void receivedRespone(QString topicName, QByteArray data );

};

#endif // MQTTCOMUNICATION_H
