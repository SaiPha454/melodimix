/****************************************************************************
** Meta object code from reading C++ file 'melodimix.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MelodiMix/melodimix.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'melodimix.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMelodiMixENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMelodiMixENDCLASS = QtMocHelpers::stringData(
    "MelodiMix",
    "playListChange",
    "",
    "Enums::PlayListType",
    "on_home_nav_clicked",
    "on_library_nav_clicked",
    "on_fav_nav_clicked",
    "on_import_nav_clicked",
    "onMusicItemClicked",
    "QListWidgetItem*",
    "item",
    "skip",
    "on_import_btn_clicked",
    "on_add_to_fav_btn_clciked",
    "on_fav_music_clicked",
    "on_playlist_change",
    "load_library",
    "on_player_end",
    "QMediaPlayer::MediaStatus",
    "status"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMelodiMixENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   95,    2, 0x08,    3 /* Private */,
       5,    0,   96,    2, 0x08,    4 /* Private */,
       6,    0,   97,    2, 0x08,    5 /* Private */,
       7,    0,   98,    2, 0x08,    6 /* Private */,
       8,    1,   99,    2, 0x08,    7 /* Private */,
      11,    0,  102,    2, 0x08,    9 /* Private */,
      12,    0,  103,    2, 0x08,   10 /* Private */,
      13,    0,  104,    2, 0x08,   11 /* Private */,
      14,    1,  105,    2, 0x08,   12 /* Private */,
      15,    1,  108,    2, 0x08,   14 /* Private */,
      16,    0,  111,    2, 0x08,   16 /* Private */,
      17,    1,  112,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

 // enums: name, alias, flags, count, data

 // enum data: key, value

       0        // eod
};

Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_CLASSMelodiMixENDCLASS[] = {
    QMetaObject::SuperData::link<Enums::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject MelodiMix::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMelodiMixENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMelodiMixENDCLASS,
    qt_static_metacall,
    qt_meta_extradata_CLASSMelodiMixENDCLASS,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMelodiMixENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MelodiMix, std::true_type>,
        // method 'playListChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Enums::PlayListType, std::false_type>,
        // method 'on_home_nav_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_library_nav_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_fav_nav_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_import_nav_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMusicItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'skip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_import_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_to_fav_btn_clciked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_fav_music_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_playlist_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Enums::PlayListType, std::false_type>,
        // method 'load_library'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player_end'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>
    >,
    nullptr
} };

void MelodiMix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MelodiMix *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playListChange((*reinterpret_cast< std::add_pointer_t<Enums::PlayListType>>(_a[1]))); break;
        case 1: _t->on_home_nav_clicked(); break;
        case 2: _t->on_library_nav_clicked(); break;
        case 3: _t->on_fav_nav_clicked(); break;
        case 4: _t->on_import_nav_clicked(); break;
        case 5: _t->onMusicItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 6: _t->skip(); break;
        case 7: _t->on_import_btn_clicked(); break;
        case 8: _t->on_add_to_fav_btn_clciked(); break;
        case 9: _t->on_fav_music_clicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 10: _t->on_playlist_change((*reinterpret_cast< std::add_pointer_t<Enums::PlayListType>>(_a[1]))); break;
        case 11: _t->load_library(); break;
        case 12: _t->on_player_end((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MelodiMix::*)(Enums::PlayListType );
            if (_t _q_method = &MelodiMix::playListChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MelodiMix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MelodiMix::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMelodiMixENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MelodiMix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MelodiMix::playListChange(Enums::PlayListType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
