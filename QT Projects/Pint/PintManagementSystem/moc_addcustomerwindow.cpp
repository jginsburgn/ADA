/****************************************************************************
** Meta object code from reading C++ file 'addcustomerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addcustomerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addcustomerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddCustomerWindow_t {
    QByteArrayData data[11];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddCustomerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddCustomerWindow_t qt_meta_stringdata_AddCustomerWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AddCustomerWindow"
QT_MOC_LITERAL(1, 18, 26), // "on_rfcLineEdit_textChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "arg1"
QT_MOC_LITERAL(4, 51, 26), // "on_nameLineEdit_textEdited"
QT_MOC_LITERAL(5, 78, 28), // "on_addLocationButton_clicked"
QT_MOC_LITERAL(6, 107, 27), // "on_addContactButton_clicked"
QT_MOC_LITERAL(7, 135, 28), // "on_addCustomerButton_clicked"
QT_MOC_LITERAL(8, 164, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(9, 188, 11), // "AddLocation"
QT_MOC_LITERAL(10, 200, 10) // "AddContact"

    },
    "AddCustomerWindow\0on_rfcLineEdit_textChanged\0"
    "\0arg1\0on_nameLineEdit_textEdited\0"
    "on_addLocationButton_clicked\0"
    "on_addContactButton_clicked\0"
    "on_addCustomerButton_clicked\0"
    "on_cancelButton_clicked\0AddLocation\0"
    "AddContact"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddCustomerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddCustomerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddCustomerWindow *_t = static_cast<AddCustomerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_rfcLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_nameLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_addLocationButton_clicked(); break;
        case 3: _t->on_addContactButton_clicked(); break;
        case 4: _t->on_addCustomerButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->AddLocation(); break;
        case 7: _t->AddContact(); break;
        default: ;
        }
    }
}

const QMetaObject AddCustomerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddCustomerWindow.data,
      qt_meta_data_AddCustomerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddCustomerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddCustomerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddCustomerWindow.stringdata0))
        return static_cast<void*>(const_cast< AddCustomerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddCustomerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
