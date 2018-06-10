#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QtMqtt/QtMqtt>
#include "MqttComunication.h"
#include "AppDefine.h"

enum class CAMERA_ID: int
{
    CAMERA_ID_00 = 100,
    CAMERA_ID_01,
    CAMERA_ID_02,
    CAMERA_ID_03,
    CAMERA_ID_04,
    CAMERA_ID_05,
    CAMERA_ID_06,
    CAMERA_ID_07,
    CAMERA_ID_08,
    CAMERA_ID_09,
    CAMERA_ID_10,
    CAMERA_ID_11,
    CAMERA_ID_12,
    CAMERA_ID_13,
    CAMERA_ID_14,
    CAMERA_ID_15,
    CAMERA_ID_16,
    CAMERA_ID_17,
    CAMERA_ID_18,
    CAMERA_ID_19,
    CAMERA_ID_20,
    CAMERA_ID_21,
    CAMERA_ID_22,
    CAMERA_ID_23,
    CAMERA_ID_24,
    CAMERA_ID_25,
    CAMERA_ID_26,
    CAMERA_ID_27,
    CAMERA_ID_28,
    CAMERA_ID_29,
    CAMERA_ID_30,
    CAMERA_ID_31,
    CAMERA_ID_32,
    CAMERA_ID_33,
    CAMERA_ID_34,
    CAMERA_ID_35,
    CAMERA_ID_36,
    CAMERA_ID_37,
    CAMERA_ID_38,
    CAMERA_ID_39,
    CAMERA_ID_40,
    CAMERA_ID_41,
    CAMERA_ID_42,
    CAMERA_ID_43,

    CAMERA_ID_MAX,
};

enum class CAMERA_ACRIVED_INDEX: int
{
    INDEX_0 = 0,
    INDEX_1,
    INDEX_2,
    INDEX_3,
    INDEX_4,
};
typedef struct mapping_common{
    QString     m_label;
    int         m_activedIndex;
    bool        m_connectionStatus;
    QString     m_subTopic;
    QString     m_pubTopic;
}MAPPING_SETUP;

const QMap<CAMERA_ID, MAPPING_SETUP> TABLE_CAMERA {
    {CAMERA_ID::CAMERA_ID_00,             {"CAMERA 00", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_00_RESP" ,"CAMERA_00_REQ" }},
    {CAMERA_ID::CAMERA_ID_01,             {"CAMERA 01", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_01_RESP" ,"CAMERA_01_REQ" }},
    {CAMERA_ID::CAMERA_ID_02,             {"CAMERA 02", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_02_RESP" ,"CAMERA_02_REQ" }},
    {CAMERA_ID::CAMERA_ID_03,             {"CAMERA 03", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_03_RESP" ,"CAMERA_03_REQ" }},
    {CAMERA_ID::CAMERA_ID_04,             {"CAMERA 04", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_04_RESP" ,"CAMERA_04_REQ" }},
    {CAMERA_ID::CAMERA_ID_05,             {"CAMERA 05", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_05_RESP" ,"CAMERA_05_REQ" }},
    {CAMERA_ID::CAMERA_ID_06,             {"CAMERA 06", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_06_RESP" ,"CAMERA_06_REQ" }},
    {CAMERA_ID::CAMERA_ID_07,             {"CAMERA 07", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_07_RESP" ,"CAMERA_07_REQ" }},
    {CAMERA_ID::CAMERA_ID_08,             {"CAMERA 08", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_08_RESP" ,"CAMERA_08_REQ" }},
    {CAMERA_ID::CAMERA_ID_09,             {"CAMERA 09", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_09_RESP" ,"CAMERA_09_REQ" }},
    {CAMERA_ID::CAMERA_ID_10,             {"CAMERA 10", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_10_RESP" ,"CAMERA_10_REQ" }},
    {CAMERA_ID::CAMERA_ID_11,             {"CAMERA 11", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_11_RESP" ,"CAMERA_11_REQ" }},
    {CAMERA_ID::CAMERA_ID_12,             {"CAMERA 12", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_12_RESP" ,"CAMERA_12_REQ" }},
    {CAMERA_ID::CAMERA_ID_13,             {"CAMERA 13", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_13_RESP" ,"CAMERA_13_REQ" }},
    {CAMERA_ID::CAMERA_ID_14,             {"CAMERA 14", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_14_RESP" ,"CAMERA_14_REQ" }},
    {CAMERA_ID::CAMERA_ID_15,             {"CAMERA 15", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_15_RESP" ,"CAMERA_15_REQ" }},
    {CAMERA_ID::CAMERA_ID_16,             {"CAMERA 16", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_16_RESP" ,"CAMERA_16_REQ" }},
    {CAMERA_ID::CAMERA_ID_17,             {"CAMERA 17", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_17_RESP" ,"CAMERA_17_REQ" }},
    {CAMERA_ID::CAMERA_ID_18,             {"CAMERA 18", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_18_RESP" ,"CAMERA_18_REQ" }},
    {CAMERA_ID::CAMERA_ID_19,             {"CAMERA 19", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_19_RESP" ,"CAMERA_19_REQ" }},
    {CAMERA_ID::CAMERA_ID_20,             {"CAMERA 20", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_20_RESP" ,"CAMERA_20_REQ" }},
    {CAMERA_ID::CAMERA_ID_21,             {"CAMERA 21", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_21_RESP" ,"CAMERA_21_REQ" }},
    {CAMERA_ID::CAMERA_ID_22,             {"CAMERA 22", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_22_RESP" ,"CAMERA_22_REQ" }},
    {CAMERA_ID::CAMERA_ID_23,             {"CAMERA 23", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_23_RESP" ,"CAMERA_23_REQ" }},
    {CAMERA_ID::CAMERA_ID_24,             {"CAMERA 24", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_24_RESP" ,"CAMERA_24_REQ" }},
    {CAMERA_ID::CAMERA_ID_25,             {"CAMERA 25", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_25_RESP" ,"CAMERA_25_REQ" }},
    {CAMERA_ID::CAMERA_ID_26,             {"CAMERA 26", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_26_RESP" ,"CAMERA_26_REQ" }},
    {CAMERA_ID::CAMERA_ID_27,             {"CAMERA 27", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_27_RESP" ,"CAMERA_27_REQ" }},
    {CAMERA_ID::CAMERA_ID_28,             {"CAMERA 28", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_28_RESP" ,"CAMERA_28_REQ" }},
    {CAMERA_ID::CAMERA_ID_29,             {"CAMERA 29", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_29_RESP" ,"CAMERA_29_REQ" }},
    {CAMERA_ID::CAMERA_ID_30,             {"CAMERA 30", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_30_RESP" ,"CAMERA_30_REQ" }},
    {CAMERA_ID::CAMERA_ID_31,             {"CAMERA 31", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_31_RESP" ,"CAMERA_31_REQ" }},
    {CAMERA_ID::CAMERA_ID_32,             {"CAMERA 32", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_32_RESP" ,"CAMERA_32_REQ" }},
    {CAMERA_ID::CAMERA_ID_33,             {"CAMERA 33", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_33_RESP" ,"CAMERA_33_REQ" }},
    {CAMERA_ID::CAMERA_ID_34,             {"CAMERA 34", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_34_RESP" ,"CAMERA_34_REQ" }},
    {CAMERA_ID::CAMERA_ID_35,             {"CAMERA 35", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_35_RESP" ,"CAMERA_35_REQ" }},
    {CAMERA_ID::CAMERA_ID_36,             {"CAMERA 36", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_36_RESP" ,"CAMERA_36_REQ" }},
    {CAMERA_ID::CAMERA_ID_37,             {"CAMERA 37", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_37_RESP" ,"CAMERA_37_REQ" }},
    {CAMERA_ID::CAMERA_ID_38,             {"CAMERA 38", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_38_RESP" ,"CAMERA_38_REQ" }},
    {CAMERA_ID::CAMERA_ID_39,             {"CAMERA 39", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_39_RESP" ,"CAMERA_39_REQ" }},
    {CAMERA_ID::CAMERA_ID_40,             {"CAMERA 40", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_40_RESP" ,"CAMERA_40_REQ" }},
    {CAMERA_ID::CAMERA_ID_41,             {"CAMERA 41", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_41_RESP" ,"CAMERA_41_REQ" }},
    {CAMERA_ID::CAMERA_ID_42,             {"CAMERA 42", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_42_RESP" ,"CAMERA_42_REQ" }},
    {CAMERA_ID::CAMERA_ID_43,             {"CAMERA 43", (int)CAMERA_ACRIVED_INDEX::INDEX_0, false   ,"CAMERA_43_RESP" ,"CAMERA_43_REQ" }},
};

class ComponentSettup :public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int      idx                 READ idx                WRITE setIdx                NOTIFY idxChanged           )
    Q_PROPERTY(QString  label               READ label              WRITE setLabel              NOTIFY labelChanged         )
    Q_PROPERTY(int      activedIndex        READ activedIndex       WRITE setActivedIndex       NOTIFY activedIndexChanged)
    Q_PROPERTY(bool     connectionStatus    READ connectionStatus   WRITE setConnectionStatus   NOTIFY connectionStatusChanged)
    Q_PROPERTY(QString  subTopic            READ subTopic           WRITE setSubTopic           NOTIFY subTopicChanged)
    Q_PROPERTY(QString  pubTopic            READ pubTopic           WRITE setPubTopic           NOTIFY pubTopicChanged)
signals:
    void idxChanged();
    void labelChanged();
    void activedIndexChanged();
    void connectionStatusChanged();
    void subTopicChanged();
    void pubTopicChanged();

public:
    ComponentSettup(int _idx, QString _label, int _activedIndex, bool _connectionStatus, QString _subTopic, QString _pubTopic ):
        m_idx(_idx), m_label(_label), m_activedIndex(_activedIndex), m_connectionStatus(_connectionStatus), m_subTopic(_subTopic), m_pubTopic(_pubTopic)
    {

    }

    ~ComponentSettup(){}
    int         idx(){return m_idx;}
    QString     label(){return m_label;}
    int         activedIndex(){return m_activedIndex;}
    bool        connectionStatus(){return m_connectionStatus;}
    QString     subTopic(){return m_subTopic;}
    QString     pubTopic(){return m_pubTopic;}

    void setIdx(int _idx){
        if(_idx!=m_idx){
            m_idx=_idx;
            emit idxChanged();
        }
    }
    void setLabel(QString _label){
        if(_label!=m_label){
            m_label=_label;
            emit labelChanged();
        }
    }
    void setActivedIndex(int _activedIndex){
        if(_activedIndex!=m_activedIndex){
            m_activedIndex=_activedIndex;
            emit activedIndexChanged();
        }
    }

    void setConnectionStatus(bool _connectionStatus){
        if(_connectionStatus != m_connectionStatus){
            m_connectionStatus=_connectionStatus;
            emit connectionStatusChanged();
        }
    }

    void setSubTopic(QString _subTopic){
        if(_subTopic != m_subTopic){
            m_subTopic=_subTopic;
            emit subTopicChanged();
        }
    }
    void setPubTopic(QString _pubTopic){
        if(_pubTopic != m_pubTopic){
            m_pubTopic=_pubTopic;
            emit pubTopicChanged();
        }
    }


private:
    int         m_idx;
    QString     m_label;
    int         m_activedIndex;
    bool        m_connectionStatus;
    QString     m_subTopic;
    QString     m_pubTopic;
};

class MyModel : public QObject
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = nullptr);

    Q_PROPERTY(bool showPopupCheckConn READ showPopupCheckConn WRITE setShowPopupCheckConn NOTIFY showPopupCheckConnChanged)
    Q_PROPERTY(QList<QObject* > listCameraSetting READ listCameraSetting WRITE setListCameraSetting NOTIFY listCameraSettingChanged)
    Q_PROPERTY(int currentCamera READ currentCamera WRITE setCurrentCamera NOTIFY currentCameraChanged)
    Q_PROPERTY(bool connectedServer READ connectedServer WRITE setConnectedServer NOTIFY connectedServerChanged)
    Q_INVOKABLE void setPosition(int CameraID, int position);

private:
    static MyModel* m_instantce;
    bool m_showPopupCheckConn;
    QList<QObject*> m_listCameraSetting;
    int m_currentCamera;
    bool m_connectedServer;
    MqttComunication * m_mqtt;

public:
    static MyModel* getInstance();
    void connectToMqttSignal();
    void initData();
    void saveHistoryData(QList<QObject *> &data);
    void loadHistoryData();

    QList<QObject *> listCameraSetting();
    void setListCameraSetting(QList<QObject* > _listCameraSetting);
    void creatListCameraSetting();
    void clearListCameraSetting(QList<QObject *> &listModel);
    void setPropertyCameraSetting(const char *_namePr, int _idx, QVariant _data);
    QVariant getPropertyCameraSetting(const char *_namePr, int _idx);
    int currentCamera();
    void setCurrentCamera(int currentCam);

    bool showPopupCheckConn();
    void setShowPopupCheckConn(bool data);

    bool connectedServer();
    void setConnectedServer(bool data);

signals:
    void showPopupCheckConnChanged();
    void listCameraSettingChanged();
    void currentCameraChanged();
    void publishData(QString topicName, int data);
    void connectedServerChanged();

public slots:
    void slotReceivedResponeFromBroker(QString topicName, QByteArray data );
};

#endif // MYMODEL_H
