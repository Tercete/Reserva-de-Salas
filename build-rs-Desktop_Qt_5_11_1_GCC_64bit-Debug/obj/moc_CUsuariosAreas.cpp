/****************************************************************************
** Meta object code from reading C++ file 'CUsuariosAreas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs/src/CUsuariosAreas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CUsuariosAreas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CUsuariosAreas_t {
    QByteArrayData data[10];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CUsuariosAreas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CUsuariosAreas_t qt_meta_stringdata_CUsuariosAreas = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CUsuariosAreas"
QT_MOC_LITERAL(1, 15, 16), // "on_tbAdd_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "on_tbAddAll_clicked"
QT_MOC_LITERAL(4, 53, 19), // "on_tbRemove_clicked"
QT_MOC_LITERAL(5, 73, 22), // "on_tbRemoveAll_clicked"
QT_MOC_LITERAL(6, 96, 24), // "on_lsAreas_doubleClicked"
QT_MOC_LITERAL(7, 121, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 133, 5), // "index"
QT_MOC_LITERAL(9, 139, 28) // "on_lsUserAreas_doubleClicked"

    },
    "CUsuariosAreas\0on_tbAdd_clicked\0\0"
    "on_tbAddAll_clicked\0on_tbRemove_clicked\0"
    "on_tbRemoveAll_clicked\0on_lsAreas_doubleClicked\0"
    "QModelIndex\0index\0on_lsUserAreas_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CUsuariosAreas[] = {

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
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void CUsuariosAreas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CUsuariosAreas *_t = static_cast<CUsuariosAreas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tbAdd_clicked(); break;
        case 1: _t->on_tbAddAll_clicked(); break;
        case 2: _t->on_tbRemove_clicked(); break;
        case 3: _t->on_tbRemoveAll_clicked(); break;
        case 4: _t->on_lsAreas_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_lsUserAreas_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CUsuariosAreas::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CUsuariosAreas.data,
      qt_meta_data_CUsuariosAreas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CUsuariosAreas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CUsuariosAreas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CUsuariosAreas.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::frUsersAreas"))
        return static_cast< Ui::frUsersAreas*>(this);
    return QDialog::qt_metacast(_clname);
}

int CUsuariosAreas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
