/****************************************************************************
** Meta object code from reading C++ file 'CReservaItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs/src/CReservaItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CReservaItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CReservaItem_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CReservaItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CReservaItem_t qt_meta_stringdata_CReservaItem = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CReservaItem"
QT_MOC_LITERAL(1, 13, 7), // "onClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "ok"
QT_MOC_LITERAL(4, 25, 6), // "cancel"
QT_MOC_LITERAL(5, 32, 10), // "onValidate"
QT_MOC_LITERAL(6, 43, 28), // "on_cbRecorrente_stateChanged"
QT_MOC_LITERAL(7, 72, 5), // "state"
QT_MOC_LITERAL(8, 78, 40), // "on_cbTipoRecorrencia_currentI..."
QT_MOC_LITERAL(9, 119, 5) // "index"

    },
    "CReservaItem\0onClose\0\0ok\0cancel\0"
    "onValidate\0on_cbRecorrente_stateChanged\0"
    "state\0on_cbTipoRecorrencia_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CReservaItem[] = {

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
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void CReservaItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CReservaItem *_t = static_cast<CReservaItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->ok(); break;
        case 2: _t->cancel(); break;
        case 3: _t->onValidate(); break;
        case 4: _t->on_cbRecorrente_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_cbTipoRecorrencia_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CReservaItem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CReservaItem.data,
      qt_meta_data_CReservaItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CReservaItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CReservaItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CReservaItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::Reserva"))
        return static_cast< Ui::Reserva*>(this);
    return QDialog::qt_metacast(_clname);
}

int CReservaItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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