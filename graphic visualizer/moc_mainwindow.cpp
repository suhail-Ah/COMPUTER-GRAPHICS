/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[188];
    char stringdata0[1429];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 17), // "showMousePosition"
QT_MOC_LITERAL(44, 7), // "QPoint&"
QT_MOC_LITERAL(52, 3), // "pos"
QT_MOC_LITERAL(56, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(78, 20), // "on_show_grid_clicked"
QT_MOC_LITERAL(99, 17), // "point_with_colour"
QT_MOC_LITERAL(117, 1), // "x"
QT_MOC_LITERAL(119, 1), // "y"
QT_MOC_LITERAL(121, 2), // "c1"
QT_MOC_LITERAL(124, 2), // "c2"
QT_MOC_LITERAL(127, 2), // "c3"
QT_MOC_LITERAL(130, 20), // "on_show_axis_clicked"
QT_MOC_LITERAL(151, 5), // "delay"
QT_MOC_LITERAL(157, 1), // "n"
QT_MOC_LITERAL(159, 20), // "on_Draw_line_clicked"
QT_MOC_LITERAL(180, 21), // "on_set_point1_clicked"
QT_MOC_LITERAL(202, 21), // "on_set_point2_clicked"
QT_MOC_LITERAL(224, 21), // "on_set_center_clicked"
QT_MOC_LITERAL(246, 22), // "on_draw_circle_clicked"
QT_MOC_LITERAL(269, 29), // "on_set_Ellipse_center_clicked"
QT_MOC_LITERAL(299, 23), // "on_draw_ellipse_clicked"
QT_MOC_LITERAL(323, 23), // "on_Draw_Polygon_clicked"
QT_MOC_LITERAL(347, 22), // "on_Take_points_clicked"
QT_MOC_LITERAL(370, 12), // "draw_my_line"
QT_MOC_LITERAL(383, 2), // "x1"
QT_MOC_LITERAL(386, 2), // "x2"
QT_MOC_LITERAL(389, 2), // "y1"
QT_MOC_LITERAL(392, 2), // "y2"
QT_MOC_LITERAL(395, 17), // "std::vector<int>&"
QT_MOC_LITERAL(413, 4), // "scan"
QT_MOC_LITERAL(418, 16), // "boundaryFillUtil"
QT_MOC_LITERAL(435, 16), // "std::vector<int>"
QT_MOC_LITERAL(452, 8), // "newColor"
QT_MOC_LITERAL(461, 9), // "edgeColor"
QT_MOC_LITERAL(471, 4), // "flag"
QT_MOC_LITERAL(476, 6), // "point2"
QT_MOC_LITERAL(483, 13), // "floodFillUtil"
QT_MOC_LITERAL(497, 7), // "inColor"
QT_MOC_LITERAL(505, 19), // "on_scanline_clicked"
QT_MOC_LITERAL(525, 21), // "on_flood_fill_clicked"
QT_MOC_LITERAL(547, 33), // "on_take_point_for_filling_cli..."
QT_MOC_LITERAL(581, 23), // "on_flood_fill_2_clicked"
QT_MOC_LITERAL(605, 23), // "on_flood_fill_4_clicked"
QT_MOC_LITERAL(629, 25), // "on_boundry_fill_4_clicked"
QT_MOC_LITERAL(655, 11), // "polygonDraw"
QT_MOC_LITERAL(667, 22), // "on_Translation_clicked"
QT_MOC_LITERAL(690, 25), // "on_Rotate_polygon_clicked"
QT_MOC_LITERAL(716, 26), // "on_Scale_wrt_orgin_clicked"
QT_MOC_LITERAL(743, 26), // "on_Shear_wrt_orgin_clicked"
QT_MOC_LITERAL(770, 26), // "on_Reflect_on_axis_clicked"
QT_MOC_LITERAL(797, 30), // "on_Reflection_wrt_line_clicked"
QT_MOC_LITERAL(828, 27), // "on_Rotate_wrt_point_clicked"
QT_MOC_LITERAL(856, 26), // "on_Scale_wrt_point_clicked"
QT_MOC_LITERAL(883, 32), // "on_Taking_clipping_lines_clicked"
QT_MOC_LITERAL(916, 21), // "on_Clip_lines_clicked"
QT_MOC_LITERAL(938, 26), // "on_P1_of_clip_line_clicked"
QT_MOC_LITERAL(965, 23), // "on_P2_clip_line_clicked"
QT_MOC_LITERAL(989, 7), // "DDAline"
QT_MOC_LITERAL(997, 1), // "r"
QT_MOC_LITERAL(999, 1), // "g"
QT_MOC_LITERAL(1001, 1), // "b"
QT_MOC_LITERAL(1003, 6), // "cpoint"
QT_MOC_LITERAL(1010, 19), // "cohenSutherlandClip"
QT_MOC_LITERAL(1030, 18), // "on_Cornor1_clicked"
QT_MOC_LITERAL(1049, 18), // "on_Cornor2_clicked"
QT_MOC_LITERAL(1068, 11), // "draw_Window"
QT_MOC_LITERAL(1080, 11), // "computeCode"
QT_MOC_LITERAL(1092, 2), // "xa"
QT_MOC_LITERAL(1095, 2), // "ya"
QT_MOC_LITERAL(1098, 23), // "on_Polygon_clip_clicked"
QT_MOC_LITERAL(1122, 12), // "suthHodgClip"
QT_MOC_LITERAL(1135, 4), // "clip"
QT_MOC_LITERAL(1140, 11), // "x_intersect"
QT_MOC_LITERAL(1152, 2), // "x3"
QT_MOC_LITERAL(1155, 2), // "y3"
QT_MOC_LITERAL(1158, 2), // "x4"
QT_MOC_LITERAL(1161, 2), // "y4"
QT_MOC_LITERAL(1164, 11), // "y_intersect"
QT_MOC_LITERAL(1176, 9), // "poly_draw"
QT_MOC_LITERAL(1186, 31), // "std::vector<std::pair<int,int>>"
QT_MOC_LITERAL(1218, 5), // "vlist"
QT_MOC_LITERAL(1224, 18), // "on_DDALine_clicked"
QT_MOC_LITERAL(1243, 16), // "storeEdgeInTable"
QT_MOC_LITERAL(1260, 13), // "initEdgeTable"
QT_MOC_LITERAL(1274, 20), // "on_setvertex_clicked"
QT_MOC_LITERAL(1295, 22), // "on_setbezpoint_clicked"
QT_MOC_LITERAL(1318, 24), // "on_clearbezpoint_clicked"
QT_MOC_LITERAL(1343, 26), // "on_drawBezierCurve_clicked"
QT_MOC_LITERAL(1370, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(1394, 17), // "on_Takep3_clicked"
QT_MOC_LITERAL(1412, 16) // "on_Take4_clicked"

    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0on_pushButton_clicked\0"
    "on_show_grid_clicked\0point_with_colour\0"
    "x\0y\0c1\0c2\0c3\0on_show_axis_clicked\0"
    "delay\0n\0on_Draw_line_clicked\0"
    "on_set_point1_clicked\0on_set_point2_clicked\0"
    "on_set_center_clicked\0on_draw_circle_clicked\0"
    "on_set_Ellipse_center_clicked\0"
    "on_draw_ellipse_clicked\0on_Draw_Polygon_clicked\0"
    "on_Take_points_clicked\0draw_my_line\0"
    "x1\0x2\0y1\0y2\0std::vector<int>&\0scan\0"
    "boundaryFillUtil\0std::vector<int>\0"
    "newColor\0edgeColor\0flag\0point2\0"
    "floodFillUtil\0inColor\0on_scanline_clicked\0"
    "on_flood_fill_clicked\0"
    "on_take_point_for_filling_clicked\0"
    "on_flood_fill_2_clicked\0on_flood_fill_4_clicked\0"
    "on_boundry_fill_4_clicked\0polygonDraw\0"
    "on_Translation_clicked\0on_Rotate_polygon_clicked\0"
    "on_Scale_wrt_orgin_clicked\0"
    "on_Shear_wrt_orgin_clicked\0"
    "on_Reflect_on_axis_clicked\0"
    "on_Reflection_wrt_line_clicked\0"
    "on_Rotate_wrt_point_clicked\0"
    "on_Scale_wrt_point_clicked\0"
    "on_Taking_clipping_lines_clicked\0"
    "on_Clip_lines_clicked\0on_P1_of_clip_line_clicked\0"
    "on_P2_clip_line_clicked\0DDAline\0r\0g\0"
    "b\0cpoint\0cohenSutherlandClip\0"
    "on_Cornor1_clicked\0on_Cornor2_clicked\0"
    "draw_Window\0computeCode\0xa\0ya\0"
    "on_Polygon_clip_clicked\0suthHodgClip\0"
    "clip\0x_intersect\0x3\0y3\0x4\0y4\0y_intersect\0"
    "poly_draw\0std::vector<std::pair<int,int>>\0"
    "vlist\0on_DDALine_clicked\0storeEdgeInTable\0"
    "initEdgeTable\0on_setvertex_clicked\0"
    "on_setbezpoint_clicked\0on_clearbezpoint_clicked\0"
    "on_drawBezierCurve_clicked\0"
    "on_pushButton_2_clicked\0on_Takep3_clicked\0"
    "on_Take4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  404,    2, 0x0a,    1 /* Public */,
       3,    1,  405,    2, 0x0a,    2 /* Public */,
       6,    0,  408,    2, 0x08,    4 /* Private */,
       7,    0,  409,    2, 0x08,    5 /* Private */,
       8,    5,  410,    2, 0x08,    6 /* Private */,
      14,    0,  421,    2, 0x08,   12 /* Private */,
      15,    1,  422,    2, 0x08,   13 /* Private */,
      17,    0,  425,    2, 0x08,   15 /* Private */,
      18,    0,  426,    2, 0x08,   16 /* Private */,
      19,    0,  427,    2, 0x08,   17 /* Private */,
      20,    0,  428,    2, 0x08,   18 /* Private */,
      21,    0,  429,    2, 0x08,   19 /* Private */,
      22,    0,  430,    2, 0x08,   20 /* Private */,
      23,    0,  431,    2, 0x08,   21 /* Private */,
      24,    0,  432,    2, 0x08,   22 /* Private */,
      25,    0,  433,    2, 0x08,   23 /* Private */,
      26,    5,  434,    2, 0x08,   24 /* Private */,
      33,    5,  445,    2, 0x08,   30 /* Private */,
      38,    5,  456,    2, 0x08,   36 /* Private */,
      39,    5,  467,    2, 0x08,   42 /* Private */,
      41,    0,  478,    2, 0x08,   48 /* Private */,
      42,    0,  479,    2, 0x08,   49 /* Private */,
      43,    0,  480,    2, 0x08,   50 /* Private */,
      44,    0,  481,    2, 0x08,   51 /* Private */,
      45,    0,  482,    2, 0x08,   52 /* Private */,
      46,    0,  483,    2, 0x08,   53 /* Private */,
      47,    0,  484,    2, 0x08,   54 /* Private */,
      48,    0,  485,    2, 0x08,   55 /* Private */,
      49,    0,  486,    2, 0x08,   56 /* Private */,
      50,    0,  487,    2, 0x08,   57 /* Private */,
      51,    0,  488,    2, 0x08,   58 /* Private */,
      52,    0,  489,    2, 0x08,   59 /* Private */,
      53,    0,  490,    2, 0x08,   60 /* Private */,
      54,    0,  491,    2, 0x08,   61 /* Private */,
      55,    0,  492,    2, 0x08,   62 /* Private */,
      56,    0,  493,    2, 0x08,   63 /* Private */,
      57,    0,  494,    2, 0x08,   64 /* Private */,
      58,    0,  495,    2, 0x08,   65 /* Private */,
      59,    0,  496,    2, 0x08,   66 /* Private */,
      60,    3,  497,    2, 0x08,   67 /* Private */,
      64,    5,  504,    2, 0x08,   71 /* Private */,
      64,    4,  515,    2, 0x28,   77 /* Private | MethodCloned */,
      64,    3,  524,    2, 0x28,   82 /* Private | MethodCloned */,
      64,    2,  531,    2, 0x28,   86 /* Private | MethodCloned */,
      65,    4,  536,    2, 0x08,   89 /* Private */,
      66,    0,  545,    2, 0x08,   94 /* Private */,
      67,    0,  546,    2, 0x08,   95 /* Private */,
      68,    0,  547,    2, 0x08,   96 /* Private */,
      69,    2,  548,    2, 0x08,   97 /* Private */,
      72,    0,  553,    2, 0x08,  100 /* Private */,
      73,    0,  554,    2, 0x08,  101 /* Private */,
      74,    4,  555,    2, 0x08,  102 /* Private */,
      75,    8,  564,    2, 0x08,  107 /* Private */,
      80,    8,  581,    2, 0x08,  116 /* Private */,
      81,    4,  598,    2, 0x08,  125 /* Private */,
      84,    0,  607,    2, 0x08,  130 /* Private */,
      85,    4,  608,    2, 0x08,  131 /* Private */,
      86,    0,  617,    2, 0x08,  136 /* Private */,
      87,    0,  618,    2, 0x08,  137 /* Private */,
      88,    0,  619,    2, 0x08,  138 /* Private */,
      89,    0,  620,    2, 0x08,  139 /* Private */,
      90,    0,  621,    2, 0x08,  140 /* Private */,
      91,    0,  622,    2, 0x08,  141 /* Private */,
      92,    0,  623,    2, 0x08,  142 /* Private */,
      93,    0,  624,    2, 0x08,  143 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 31,   27,   28,   29,   30,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 34, 0x80000000 | 34, QMetaType::Int,    9,   10,   35,   36,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 34, 0x80000000 | 34, QMetaType::Int,    9,   10,   35,   40,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   61,   62,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   61,   62,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   61,   62,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   61,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   29,   28,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   70,   71,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   29,   28,   30,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   29,   28,   30,   76,   77,   78,   79,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   29,   28,   30,   76,   77,   78,   79,
    QMetaType::Void, 0x80000000 | 82, QMetaType::Int, QMetaType::Int, QMetaType::Int,   83,   61,   62,   63,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   29,   28,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< std::add_pointer_t<QPoint&>>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_show_grid_clicked(); break;
        case 4: _t->point_with_colour((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 5: _t->on_show_axis_clicked(); break;
        case 6: _t->delay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_Draw_line_clicked(); break;
        case 8: _t->on_set_point1_clicked(); break;
        case 9: _t->on_set_point2_clicked(); break;
        case 10: _t->on_set_center_clicked(); break;
        case 11: _t->on_draw_circle_clicked(); break;
        case 12: _t->on_set_Ellipse_center_clicked(); break;
        case 13: _t->on_draw_ellipse_clicked(); break;
        case 14: _t->on_Draw_Polygon_clicked(); break;
        case 15: _t->on_Take_points_clicked(); break;
        case 16: _t->draw_my_line((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<std::vector<int>&>>(_a[5]))); break;
        case 17: _t->boundaryFillUtil((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 18: _t->point2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 19: _t->floodFillUtil((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 20: _t->on_scanline_clicked(); break;
        case 21: _t->on_flood_fill_clicked(); break;
        case 22: _t->on_take_point_for_filling_clicked(); break;
        case 23: _t->on_flood_fill_2_clicked(); break;
        case 24: _t->on_flood_fill_4_clicked(); break;
        case 25: _t->on_boundry_fill_4_clicked(); break;
        case 26: _t->polygonDraw(); break;
        case 27: _t->on_Translation_clicked(); break;
        case 28: _t->on_Rotate_polygon_clicked(); break;
        case 29: _t->on_Scale_wrt_orgin_clicked(); break;
        case 30: _t->on_Shear_wrt_orgin_clicked(); break;
        case 31: _t->on_Reflect_on_axis_clicked(); break;
        case 32: _t->on_Reflection_wrt_line_clicked(); break;
        case 33: _t->on_Rotate_wrt_point_clicked(); break;
        case 34: _t->on_Scale_wrt_point_clicked(); break;
        case 35: _t->on_Taking_clipping_lines_clicked(); break;
        case 36: _t->on_Clip_lines_clicked(); break;
        case 37: _t->on_P1_of_clip_line_clicked(); break;
        case 38: _t->on_P2_clip_line_clicked(); break;
        case 39: _t->DDAline((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 40: _t->cpoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 41: _t->cpoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 42: _t->cpoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 43: _t->cpoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 44: _t->cohenSutherlandClip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 45: _t->on_Cornor1_clicked(); break;
        case 46: _t->on_Cornor2_clicked(); break;
        case 47: _t->draw_Window(); break;
        case 48: { int _r = _t->computeCode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 49: _t->on_Polygon_clip_clicked(); break;
        case 50: _t->suthHodgClip(); break;
        case 51: _t->clip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 52: { int _r = _t->x_intersect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 53: { int _r = _t->y_intersect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->poly_draw((*reinterpret_cast< std::add_pointer_t<std::vector<std::pair<int,int>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 55: _t->on_DDALine_clicked(); break;
        case 56: _t->storeEdgeInTable((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 57: _t->initEdgeTable(); break;
        case 58: _t->on_setvertex_clicked(); break;
        case 59: _t->on_setbezpoint_clicked(); break;
        case 60: _t->on_clearbezpoint_clicked(); break;
        case 61: _t->on_drawBezierCurve_clicked(); break;
        case 62: _t->on_pushButton_2_clicked(); break;
        case 63: _t->on_Takep3_clicked(); break;
        case 64: _t->on_Take4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::pair<int,int> >, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 65;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
