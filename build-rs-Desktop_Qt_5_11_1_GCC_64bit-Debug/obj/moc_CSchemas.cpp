/****************************************************************************
** Meta object code from reading C++ file 'CSchemas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs/src/CSchemas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSchemas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSchemas_t {
    QByteArrayData data[10];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSchemas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSchemas_t qt_meta_stringdata_CSchemas = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CSchemas"
QT_MOC_LITERAL(1, 9, 8), // "onAccept"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "onsliderMoved"
QT_MOC_LITERAL(4, 33, 20), // "on_tableView_pressed"
QT_MOC_LITERAL(5, 54, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 66, 5), // "index"
QT_MOC_LITERAL(7, 72, 20), // "on_pbAlterar_clicked"
QT_MOC_LITERAL(8, 93, 21), // "on_pbAdcionar_clicked"
QT_MOC_LITERAL(9, 115, 20) // "on_pbRemover_clicked"

    },
    "CSchemas\0onAccept\0\0onsliderMoved\0"
    "on_tableView_pressed\0QModelIndex\0index\0"
    "on_pbAlterar_clicked\0on_pbAdcionar_clicked\0"
    "on_pbRemover_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSchemas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSchemas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSchemas *_t = static_cast<CSchemas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onAccept(); break;
        case 1: _t->onsliderMoved(); break;
        case 2: _t->on_tableView_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_pbAlterar_clicked(); break;
        case 4: _t->on_pbAdcionar_clicked(); break;
        case 5: _t->on_pbRemover_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSchemas::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CSchemas.data,
      qt_meta_data_CSchemas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSchemas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSchemas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSchemas.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::frSchemas"))
        return static_cast< Ui::frSchemas*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSchemas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
