/****************************************************************************
** Meta object code from reading C++ file 'addcustomeraddlocationaddcontactaddphone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addcustomeraddlocationaddcontactaddphone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addcustomeraddlocationaddcontactaddphone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone_t {
    QByteArrayData data[7];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone_t qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone = {
    {
QT_MOC_LITERAL(0, 0, 40), // "AddCustomerAddLocationAddCont..."
QT_MOC_LITERAL(1, 41, 26), // "CloseUponConnectionFailure"
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 11), // "CloseAndAdd"
QT_MOC_LITERAL(4, 81, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(5, 105, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(6, 126, 21) // "on_pushButton_clicked"

    },
    "AddCustomerAddLocationAddContactAddPhone\0"
    "CloseUponConnectionFailure\0\0CloseAndAdd\0"
    "on_cancelButton_clicked\0on_addButton_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddCustomerAddLocationAddContactAddPhone[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddCustomerAddLocationAddContactAddPhone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddCustomerAddLocationAddContactAddPhone *_t = static_cast<AddCustomerAddLocationAddContactAddPhone *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseUponConnectionFailure(); break;
        case 1: _t->CloseAndAdd(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->on_addButton_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddCustomerAddLocationAddContactAddPhone::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCustomerAddLocationAddContactAddPhone::CloseUponConnectionFailure)) {
                *result = 0;
            }
        }
        {
            typedef void (AddCustomerAddLocationAddContactAddPhone::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCustomerAddLocationAddContactAddPhone::CloseAndAdd)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddCustomerAddLocationAddContactAddPhone::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone.data,
      qt_meta_data_AddCustomerAddLocationAddContactAddPhone,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddCustomerAddLocationAddContactAddPhone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddCustomerAddLocationAddContactAddPhone::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddCustomerAddLocationAddContactAddPhone.stringdata0))
        return static_cast<void*>(const_cast< AddCustomerAddLocationAddContactAddPhone*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddCustomerAddLocationAddContactAddPhone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AddCustomerAddLocationAddContactAddPhone::CloseUponConnectionFailure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AddCustomerAddLocationAddContactAddPhone::CloseAndAdd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
