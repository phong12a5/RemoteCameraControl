#include "MyModel.h"
#include <QFile>

MyModel* MyModel::m_instantce = NULL;

MyModel::MyModel(QObject *parent) : QObject(parent)
{
    m_showPopupCheckConn = false;
    m_currentCamera = (int)CAMERA_ID::CAMERA_ID_00 - ID_START;
    m_mqtt = new MqttComunication(this);
    m_connectedServer = false;
    initData();
}

void MyModel::setPosition(int CameraID, int position)
{
    DLT_LOG << "[setPosition] " << "CameraID: " << CameraID << " >> position: " << position;
    if(TABLE_CAMERA.contains(static_cast<CAMERA_ID>(CameraID)))
    {
        emit publishData(TABLE_CAMERA.value(static_cast<CAMERA_ID>(CameraID)).m_pubTopic,position);
    }
}

MyModel* MyModel::getInstance()
{
    if (!m_instantce) {
        try
        {
            m_instantce = new MyModel();
        }
        catch (std::exception& e)
        {
            DLT_LOG << "Exception " << e.what();
        }
    }
    return m_instantce;
}

void MyModel::connectToMqttSignal()
{
    DLT_LOG << "[connectToMqttSignal]";
    connect(m_mqtt,SIGNAL(receivedRespone(QString,QByteArray)),this,SLOT(slotReceivedResponeFromBroker(QString,QByteArray)));
    connect(this,SIGNAL(publishData(QString, int)), m_mqtt, SLOT(slotPublishData(QString,int)));
}


void MyModel::initData()
{
    DLT_LOG << "[initData]";
    QFile file(DATA_FILENAME);

    creatListCameraSetting();

    if(!file.exists())
    {
        DLT_LOG << DATA_FILENAME <<" has not created! >> Get default value!";
        saveHistoryData(m_listCameraSetting);
    }else
    {
        loadHistoryData();
    }
    connectToMqttSignal();
    m_mqtt->initClient();
}

void MyModel::saveHistoryData(QList<QObject *> &data)
{
    DLT_LOG << "[saveHistoryData]";
    QFile file(DATA_FILENAME);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        DLT_LOG << "Cannot Open " << DATA_FILENAME;
        return;
    }
    if(!data.isEmpty())
    {
        QVariantMap vmap;
        for(int i = 0; i < data.count(); i++){
            vmap.insert(getPropertyCameraSetting("idx",i).toString(), data.at(i)->property("activedIndex"));
        }
        QJsonDocument json = QJsonDocument::fromVariant(vmap);

        file.write(json.toJson());
        file.close();
    }else
    {
        DLT_LOG << "Can not save this data";
    }
}


void MyModel::loadHistoryData()
{
    DLT_LOG << "[loadHistoryData]";
    QFile file(DATA_FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        DLT_LOG << "Cannot Open " << DATA_FILENAME;
        return;
    }

    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    QJsonObject dataObject = JsonDocument.object();
    QStringList _listKey = dataObject.keys();
    if(!_listKey.isEmpty())
    {
        for (int i = 0; i < _listKey.length(); ++i) {
            if(TABLE_CAMERA.contains(static_cast<CAMERA_ID>(_listKey.at(i).toInt())))
                setPropertyCameraSetting("activedIndex",_listKey.at(i).toInt() - ID_START,dataObject.value(_listKey.at(i)).toVariant());
        }
    }
}

QList<QObject *> MyModel::listCameraSetting()
{
    if(m_listCameraSetting.count( ) == 0){
        this->creatListCameraSetting();
    }
    return m_listCameraSetting;
}

void MyModel::setListCameraSetting(QList<QObject *> _listCameraSetting)
{
    if(_listCameraSetting.count() > 0){
        clearListCameraSetting(_listCameraSetting);
        m_listCameraSetting = _listCameraSetting;
    }
}

void MyModel::creatListCameraSetting()
{
    DLT_LOG << "[creatListCameraSetting]";
    clearListCameraSetting(m_listCameraSetting);
    QList<CAMERA_ID> _keyList = TABLE_CAMERA.keys();
    for(int i = 0; i < _keyList.count(); i++){
        m_listCameraSetting.append(new ComponentSettup(
                                       (int)_keyList[i],
                                       TABLE_CAMERA.value(_keyList[i]).m_label,
                                       TABLE_CAMERA.value(_keyList[i]).m_activedIndex,
                                       TABLE_CAMERA.value(_keyList[i]).m_connectionStatus,
                                       TABLE_CAMERA.value(_keyList[i]).m_subTopic,
                                       TABLE_CAMERA.value(_keyList[i]).m_pubTopic));
    }
    emit listCameraSettingChanged();
}

void MyModel::clearListCameraSetting(QList<QObject *> &listModel)
{
    if(!listModel.isEmpty()){
        for(int i = 0; i < listModel.count(); i++){
            delete listModel[i];
            listModel[i] = NULL;
        }
        listModel.clear();
    }
}

void MyModel::setPropertyCameraSetting(const char *_namePr, int _idx, QVariant _data)
{
    DLT_LOG << "[setPropertyCameraSetting] >> _namePr: " << _namePr << " >> _idx: " << _idx << " >> _data: " << _data;
    if( (0 < this->m_listCameraSetting.count()) && (_idx < this->m_listCameraSetting.count())){
        this->m_listCameraSetting.at(_idx)->setProperty(_namePr, _data);
        emit listCameraSettingChanged();
    }
}

QVariant MyModel::getPropertyCameraSetting(const char *_namePr, int _idx)
{
    QVariant retValue(-1);
    if( (0 < this->m_listCameraSetting.count()) && (_idx < this->m_listCameraSetting.count())){
        retValue =  this->m_listCameraSetting.at(_idx)->property(_namePr);
    }
    return retValue;
}

int MyModel::currentCamera()
{
    return m_currentCamera;
}

void MyModel::setCurrentCamera(int currentCam)
{
    if(m_currentCamera != currentCam)
    {
        m_currentCamera = currentCam;
        emit currentCameraChanged();
    }
}

bool MyModel::showPopupCheckConn()
{
    return m_showPopupCheckConn;
}

void MyModel::setShowPopupCheckConn(bool data)
{
    if(m_showPopupCheckConn != data)
    {
        m_showPopupCheckConn =data;
        emit showPopupCheckConnChanged();
    }
}

bool MyModel::connectedServer()
{
    return m_connectedServer;
}

void MyModel::setConnectedServer(bool data)
{
    if(m_connectedServer != data)
    {
        m_connectedServer = data;
        emit connectedServerChanged();
        emit publishData(REQUESTDATA_TOPIC,0);
    }
}

void MyModel::slotReceivedResponeFromBroker(QString topicName, QByteArray data )
{
    DLT_LOG << "slotReceivedResponeFromBroker >> " << "topicName: " << topicName << " << data: " << data;
    if(m_listCameraSetting.isEmpty())
    {
        DLT_LOG << "[slotReceivedResponeFromBroker] >> list is empty";
        return;
    }
    for(int i = 0; i < m_listCameraSetting.count(); i++){
        if(getPropertyCameraSetting("subTopic",i) == topicName)
        {
            int _intData = data.toInt();
            if(_intData >= 0 && _intData <=4)
            {
                this->setPropertyCameraSetting("activedIndex",i,QVariant::fromValue(_intData));
            }
            return;
        }
    }

    if(topicName == DISCONECTED_TOPIC)
    {
        for(int i = 0; i < m_listCameraSetting.count(); i++){
            if(getPropertyCameraSetting("idx",i).toInt() == data.toInt())
            {
                int _intData = data.toInt();
                if(_intData >= static_cast<int>(CAMERA_ID::CAMERA_ID_00) && _intData < static_cast<int>(CAMERA_ID::CAMERA_ID_MAX))
                {
                    this->setPropertyCameraSetting("connectionStatus",i,QVariant::fromValue(false));
                }
                return;
            }
        }
    }else if(topicName == CONNECTED_TOPIC)
    {
        for(int i = 0; i < m_listCameraSetting.count(); i++){
            if(getPropertyCameraSetting("idx",i).toInt() == data.toInt())
            {
                int _intData = data.toInt();
                if(_intData >= static_cast<int>(CAMERA_ID::CAMERA_ID_00) && _intData < static_cast<int>(CAMERA_ID::CAMERA_ID_MAX))
                {
                    this->setPropertyCameraSetting("connectionStatus",i,QVariant::fromValue(true));
                }
                return;
            }
        }
    }
}

