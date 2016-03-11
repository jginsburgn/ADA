/****************************************************************************
** Meta object code from reading C++ file 'addcustomeraddcontact.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addcustomeraddcontact.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addcustomeraddcontact.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddCustomerAddContact_t {
    QByteArrayData data[9];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddCustomerAddContact_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddCustomerAddContact_t qt_meta_stringdata_AddCustomerAddContact = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AddCustomerAddContact"
QT_MOC_LITERAL(1, 22, 11), // "CloseAndAdd"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(4, 59, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(5, 80, 25), // "on_addPhoneButton_clicked"
QT_MOC_LITERAL(6, 106, 25), // "on_addEmailButton_clicked"
QT_MOC_LITERAL(7, 132, 8), // "AddPhone"
QT_MOC_LITERAL(8, 141, 8) // "AddEmail"

    },
    "AddCustomerAddContact\0CloseAndAdd\0\0"
    "on_cancelButton_clicked\0on_addButton_clicked\0"
    "on_addPhoneButton_clicked\0"
    "on_addEmailButton_clicked\0AddPhone\0"
    "AddEmail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddCustomerAddContact[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddCustomerAddContact::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddCustomerAddContact *_t = static_cast<AddCustomerAddContact *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseAndAdd(); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->on_addButton_clicked(); break;
        case 3: _t->on_addPhoneButton_clicked(); break;
        case 4: _t->on_addEmailButton_clicked(); break;
        case 5: _t->AddPhone(); break;
        case 6: _t->AddEmail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddCustomerAddContact::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCustomerAddContact::CloseAndAdd)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddCustomerAddContact::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddCustomerAddContact.data,
      qt_meta_data_AddCustomerAddContact,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddCustomerAddContact::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddCustomerAddContact::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddCustomerAddContact.stringdata0))
        return static_cast<void*>(const_cast< AddCustomerAddContact*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddCustomerAddContact::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void AddCustomerAddContact::CloseAndAdd()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
