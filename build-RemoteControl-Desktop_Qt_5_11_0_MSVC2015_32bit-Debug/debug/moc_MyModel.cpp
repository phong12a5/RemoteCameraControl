/****************************************************************************
** Meta object code from reading C++ file 'MyModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RemoteControl/MyModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComponentSettup_t {
    QByteArrayData data[14];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComponentSettup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComponentSettup_t qt_meta_stringdata_ComponentSettup = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ComponentSettup"
QT_MOC_LITERAL(1, 16, 10), // "idxChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "labelChanged"
QT_MOC_LITERAL(4, 41, 19), // "activedIndexChanged"
QT_MOC_LITERAL(5, 61, 23), // "connectionStatusChanged"
QT_MOC_LITERAL(6, 85, 15), // "subTopicChanged"
QT_MOC_LITERAL(7, 101, 15), // "pubTopicChanged"
QT_MOC_LITERAL(8, 117, 3), // "idx"
QT_MOC_LITERAL(9, 121, 5), // "label"
QT_MOC_LITERAL(10, 127, 12), // "activedIndex"
QT_MOC_LITERAL(11, 140, 16), // "connectionStatus"
QT_MOC_LITERAL(12, 157, 8), // "subTopic"
QT_MOC_LITERAL(13, 166, 8) // "pubTopic"

    },
    "ComponentSettup\0idxChanged\0\0labelChanged\0"
    "activedIndexChanged\0connectionStatusChanged\0"
    "subTopicChanged\0pubTopicChanged\0idx\0"
    "label\0activedIndex\0connectionStatus\0"
    "subTopic\0pubTopic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComponentSettup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::Int, 0x00495103,
      11, QMetaType::Bool, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void ComponentSettup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComponentSettup *_t = static_cast<ComponentSettup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idxChanged(); break;
        case 1: _t->labelChanged(); break;
        case 2: _t->activedIndexChanged(); break;
        case 3: _t->connectionStatusChanged(); break;
        case 4: _t->subTopicChanged(); break;
        case 5: _t->pubTopicChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::idxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::labelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::activedIndexChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::connectionStatusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::subTopicChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ComponentSettup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComponentSettup::pubTopicChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ComponentSettup *_t = static_cast<ComponentSettup *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->idx(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->label(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->activedIndex(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->connectionStatus(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->subTopic(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->pubTopic(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ComponentSettup *_t = static_cast<ComponentSettup *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIdx(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setLabel(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setActivedIndex(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setConnectionStatus(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setSubTopic(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setPubTopic(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ComponentSettup::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ComponentSettup.data,
      qt_meta_data_ComponentSettup,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ComponentSettup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComponentSettup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComponentSettup.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ComponentSettup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ComponentSettup::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ComponentSettup::labelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ComponentSettup::activedIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ComponentSettup::connectionStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ComponentSettup::subTopicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ComponentSettup::pubTopicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
struct qt_meta_stringdata_MyModel_t {
    QByteArrayData data[18];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyModel_t qt_meta_stringdata_MyModel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyModel"
QT_MOC_LITERAL(1, 8, 25), // "showPopupCheckConnChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 24), // "listCameraSettingChanged"
QT_MOC_LITERAL(4, 60, 20), // "currentCameraChanged"
QT_MOC_LITERAL(5, 81, 11), // "publishData"
QT_MOC_LITERAL(6, 93, 9), // "topicName"
QT_MOC_LITERAL(7, 103, 4), // "data"
QT_MOC_LITERAL(8, 108, 22), // "connectedServerChanged"
QT_MOC_LITERAL(9, 131, 29), // "slotReceivedResponeFromBroker"
QT_MOC_LITERAL(10, 161, 11), // "setPosition"
QT_MOC_LITERAL(11, 173, 8), // "CameraID"
QT_MOC_LITERAL(12, 182, 8), // "position"
QT_MOC_LITERAL(13, 191, 18), // "showPopupCheckConn"
QT_MOC_LITERAL(14, 210, 17), // "listCameraSetting"
QT_MOC_LITERAL(15, 228, 15), // "QList<QObject*>"
QT_MOC_LITERAL(16, 244, 13), // "currentCamera"
QT_MOC_LITERAL(17, 258, 15) // "connectedServer"

    },
    "MyModel\0showPopupCheckConnChanged\0\0"
    "listCameraSettingChanged\0currentCameraChanged\0"
    "publishData\0topicName\0data\0"
    "connectedServerChanged\0"
    "slotReceivedResponeFromBroker\0setPosition\0"
    "CameraID\0position\0showPopupCheckConn\0"
    "listCameraSetting\0QList<QObject*>\0"
    "currentCamera\0connectedServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,
       8,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   58,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    2,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    6,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

 // properties: name, type, flags
      13, QMetaType::Bool, 0x00495103,
      14, 0x80000000 | 15, 0x0049510b,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       4,

       0        // eod
};

void MyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyModel *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showPopupCheckConnChanged(); break;
        case 1: _t->listCameraSettingChanged(); break;
        case 2: _t->currentCameraChanged(); break;
        case 3: _t->publishData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->connectedServerChanged(); break;
        case 5: _t->slotReceivedResponeFromBroker((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->setPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::showPopupCheckConnChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::listCameraSettingChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::currentCameraChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyModel::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::publishData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::connectedServerChanged)) {
                *result = 4;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MyModel *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->showPopupCheckConn(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = _t->listCameraSetting(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->currentCamera(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->connectedServer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MyModel *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowPopupCheckConn(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setListCameraSetting(*reinterpret_cast< QList<QObject*>*>(_v)); break;
        case 2: _t->setCurrentCamera(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setConnectedServer(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MyModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyModel.data,
      qt_meta_data_MyModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MyModel::showPopupCheckConnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyModel::listCameraSettingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyModel::currentCameraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyModel::publishData(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyModel::connectedServerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
