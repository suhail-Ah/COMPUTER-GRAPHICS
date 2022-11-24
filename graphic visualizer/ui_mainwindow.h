/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QRadioButton *show_grid;
    QSpinBox *grid_size;
    QPushButton *show_axis;
    QFrame *line;
    QGroupBox *groupBox;
    QCheckBox *DDA_line;
    QCheckBox *Bresenham_line;
    QPushButton *Draw_line;
    QPushButton *set_point2;
    QPushButton *set_point1;
    QLabel *line_time;
    QPushButton *Draw;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QCheckBox *polar_circle;
    QCheckBox *bresenham_circle;
    QCheckBox *cartesian_circle;
    QCheckBox *mid_point_circle;
    QPushButton *set_center;
    QSpinBox *radius_of_circle;
    QLabel *label;
    QPushButton *draw_circle;
    QLabel *circle_time;
    QGroupBox *groupBox_3;
    QPushButton *set_Ellipse_center;
    QCheckBox *Polar_ellipse;
    QSpinBox *set_A;
    QLineEdit *lineEdit;
    QSpinBox *set_B;
    QLineEdit *lineEdit_2;
    QPushButton *draw_ellipse;
    QCheckBox *bresenham_ellipse;
    QGroupBox *groupBox_4;
    QCheckBox *Taking_points;
    QPushButton *Draw_Polygon;
    QPushButton *Take_points;
    QPushButton *scanline;
    QPushButton *flood_fill;
    QLabel *timeValue;
    QPushButton *take_point_for_filling;
    QPushButton *flood_fill_2;
    QPushButton *flood_fill_4;
    QPushButton *boundry_fill_4;
    QGroupBox *groupBox_5;
    QPushButton *Translation;
    QSpinBox *Tx;
    QSpinBox *Ty;
    QLabel *label_2;
    QPushButton *Rotate_polygon;
    QSpinBox *Degree;
    QLabel *label_4;
    QPushButton *Scale_wrt_orgin;
    QLabel *label_6;
    QPushButton *Shear_wrt_orgin;
    QPushButton *Reflect_on_axis;
    QCheckBox *X_axis;
    QCheckBox *Y_axis;
    QDoubleSpinBox *Sx;
    QDoubleSpinBox *Sy;
    QDoubleSpinBox *Shx;
    QDoubleSpinBox *Shy;
    QCheckBox *NShx;
    QCheckBox *NShy;
    QPushButton *Reflection_wrt_line;
    QPushButton *Takep3;
    QGroupBox *groupBox_6;
    QPushButton *Rotate_wrt_point;
    QPushButton *Scale_wrt_point;
    QGroupBox *groupBox_7;
    QPushButton *Taking_clipping_lines;
    QPushButton *Clip_lines;
    QPushButton *P1_of_clip_line;
    QPushButton *P2_clip_line;
    QPushButton *Cornor1;
    QPushButton *Cornor2;
    QGroupBox *groupBox_8;
    QPushButton *Polygon_clip;
    QPushButton *DDALine;
    QPushButton *setvertex;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_9;
    QPushButton *setbezpoint;
    QPushButton *clearbezpoint;
    QPushButton *drawBezierCurve;
    QPushButton *Take4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1685, 1233);
        MainWindow->setMinimumSize(QSize(1338, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(710, 10, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 40, 131, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(840, 10, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(850, 40, 101, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_grid = new QRadioButton(centralWidget);
        show_grid->setObjectName(QString::fromUtf8("show_grid"));
        show_grid->setGeometry(QRect(960, 10, 99, 20));
        grid_size = new QSpinBox(centralWidget);
        grid_size->setObjectName(QString::fromUtf8("grid_size"));
        grid_size->setGeometry(QRect(1050, 10, 42, 22));
        show_axis = new QPushButton(centralWidget);
        show_axis->setObjectName(QString::fromUtf8("show_axis"));
        show_axis->setGeometry(QRect(980, 30, 100, 32));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(700, 70, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(700, 60, 401, 101));
        DDA_line = new QCheckBox(groupBox);
        DDA_line->setObjectName(QString::fromUtf8("DDA_line"));
        DDA_line->setGeometry(QRect(0, 20, 85, 20));
        Bresenham_line = new QCheckBox(groupBox);
        Bresenham_line->setObjectName(QString::fromUtf8("Bresenham_line"));
        Bresenham_line->setGeometry(QRect(0, 40, 101, 20));
        Draw_line = new QPushButton(groupBox);
        Draw_line->setObjectName(QString::fromUtf8("Draw_line"));
        Draw_line->setGeometry(QRect(0, 60, 100, 32));
        set_point2 = new QPushButton(groupBox);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));
        set_point2->setGeometry(QRect(110, 20, 100, 32));
        set_point1 = new QPushButton(groupBox);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));
        set_point1->setGeometry(QRect(110, 60, 100, 32));
        line_time = new QLabel(groupBox);
        line_time->setObjectName(QString::fromUtf8("line_time"));
        line_time->setGeometry(QRect(240, 40, 131, 31));
        line_time->setFrameShape(QFrame::Panel);
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->setGeometry(QRect(710, 660, 101, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(820, 660, 101, 41));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1110, 60, 211, 191));
        polar_circle = new QCheckBox(groupBox_2);
        polar_circle->setObjectName(QString::fromUtf8("polar_circle"));
        polar_circle->setGeometry(QRect(0, 20, 85, 20));
        bresenham_circle = new QCheckBox(groupBox_2);
        bresenham_circle->setObjectName(QString::fromUtf8("bresenham_circle"));
        bresenham_circle->setGeometry(QRect(0, 40, 101, 20));
        cartesian_circle = new QCheckBox(groupBox_2);
        cartesian_circle->setObjectName(QString::fromUtf8("cartesian_circle"));
        cartesian_circle->setGeometry(QRect(0, 60, 91, 20));
        mid_point_circle = new QCheckBox(groupBox_2);
        mid_point_circle->setObjectName(QString::fromUtf8("mid_point_circle"));
        mid_point_circle->setGeometry(QRect(0, 80, 85, 20));
        set_center = new QPushButton(groupBox_2);
        set_center->setObjectName(QString::fromUtf8("set_center"));
        set_center->setGeometry(QRect(0, 130, 100, 32));
        radius_of_circle = new QSpinBox(groupBox_2);
        radius_of_circle->setObjectName(QString::fromUtf8("radius_of_circle"));
        radius_of_circle->setGeometry(QRect(130, 40, 42, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 58, 16));
        draw_circle = new QPushButton(groupBox_2);
        draw_circle->setObjectName(QString::fromUtf8("draw_circle"));
        draw_circle->setGeometry(QRect(0, 100, 100, 32));
        circle_time = new QLabel(groupBox_2);
        circle_time->setObjectName(QString::fromUtf8("circle_time"));
        circle_time->setGeometry(QRect(110, 60, 81, 31));
        circle_time->setFrameShape(QFrame::Panel);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(700, 160, 401, 80));
        set_Ellipse_center = new QPushButton(groupBox_3);
        set_Ellipse_center->setObjectName(QString::fromUtf8("set_Ellipse_center"));
        set_Ellipse_center->setGeometry(QRect(120, 20, 100, 32));
        Polar_ellipse = new QCheckBox(groupBox_3);
        Polar_ellipse->setObjectName(QString::fromUtf8("Polar_ellipse"));
        Polar_ellipse->setGeometry(QRect(0, 20, 85, 20));
        set_A = new QSpinBox(groupBox_3);
        set_A->setObjectName(QString::fromUtf8("set_A"));
        set_A->setGeometry(QRect(350, 20, 42, 22));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 20, 41, 21));
        set_B = new QSpinBox(groupBox_3);
        set_B->setObjectName(QString::fromUtf8("set_B"));
        set_B->setEnabled(true);
        set_B->setGeometry(QRect(350, 40, 42, 22));
        set_B->setMinimum(1);
        set_B->setValue(1);
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 40, 41, 21));
        draw_ellipse = new QPushButton(groupBox_3);
        draw_ellipse->setObjectName(QString::fromUtf8("draw_ellipse"));
        draw_ellipse->setGeometry(QRect(120, 50, 100, 32));
        bresenham_ellipse = new QCheckBox(groupBox_3);
        bresenham_ellipse->setObjectName(QString::fromUtf8("bresenham_ellipse"));
        bresenham_ellipse->setGeometry(QRect(0, 40, 101, 20));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(700, 240, 621, 101));
        Taking_points = new QCheckBox(groupBox_4);
        Taking_points->setObjectName(QString::fromUtf8("Taking_points"));
        Taking_points->setGeometry(QRect(0, 20, 101, 20));
        Draw_Polygon = new QPushButton(groupBox_4);
        Draw_Polygon->setObjectName(QString::fromUtf8("Draw_Polygon"));
        Draw_Polygon->setGeometry(QRect(140, 50, 100, 32));
        Take_points = new QPushButton(groupBox_4);
        Take_points->setObjectName(QString::fromUtf8("Take_points"));
        Take_points->setGeometry(QRect(0, 40, 100, 32));
        scanline = new QPushButton(groupBox_4);
        scanline->setObjectName(QString::fromUtf8("scanline"));
        scanline->setGeometry(QRect(250, 20, 100, 32));
        flood_fill = new QPushButton(groupBox_4);
        flood_fill->setObjectName(QString::fromUtf8("flood_fill"));
        flood_fill->setGeometry(QRect(140, 20, 100, 32));
        timeValue = new QLabel(groupBox_4);
        timeValue->setObjectName(QString::fromUtf8("timeValue"));
        timeValue->setGeometry(QRect(510, 20, 111, 41));
        timeValue->setFrameShape(QFrame::Panel);
        take_point_for_filling = new QPushButton(groupBox_4);
        take_point_for_filling->setObjectName(QString::fromUtf8("take_point_for_filling"));
        take_point_for_filling->setGeometry(QRect(0, 70, 100, 32));
        flood_fill_2 = new QPushButton(groupBox_4);
        flood_fill_2->setObjectName(QString::fromUtf8("flood_fill_2"));
        flood_fill_2->setGeometry(QRect(250, 50, 100, 32));
        flood_fill_4 = new QPushButton(groupBox_4);
        flood_fill_4->setObjectName(QString::fromUtf8("flood_fill_4"));
        flood_fill_4->setGeometry(QRect(360, 50, 100, 32));
        boundry_fill_4 = new QPushButton(groupBox_4);
        boundry_fill_4->setObjectName(QString::fromUtf8("boundry_fill_4"));
        boundry_fill_4->setGeometry(QRect(360, 20, 100, 32));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(700, 340, 701, 91));
        Translation = new QPushButton(groupBox_5);
        Translation->setObjectName(QString::fromUtf8("Translation"));
        Translation->setGeometry(QRect(0, 20, 100, 32));
        Tx = new QSpinBox(groupBox_5);
        Tx->setObjectName(QString::fromUtf8("Tx"));
        Tx->setGeometry(QRect(0, 50, 42, 22));
        Tx->setMinimum(-99);
        Ty = new QSpinBox(groupBox_5);
        Ty->setObjectName(QString::fromUtf8("Ty"));
        Ty->setGeometry(QRect(50, 50, 42, 22));
        Ty->setMinimum(-99);
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 81, 20));
        Rotate_polygon = new QPushButton(groupBox_5);
        Rotate_polygon->setObjectName(QString::fromUtf8("Rotate_polygon"));
        Rotate_polygon->setGeometry(QRect(110, 20, 100, 32));
        Degree = new QSpinBox(groupBox_5);
        Degree->setObjectName(QString::fromUtf8("Degree"));
        Degree->setGeometry(QRect(110, 50, 91, 22));
        Degree->setMaximum(360);
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 70, 58, 16));
        Scale_wrt_orgin = new QPushButton(groupBox_5);
        Scale_wrt_orgin->setObjectName(QString::fromUtf8("Scale_wrt_orgin"));
        Scale_wrt_orgin->setGeometry(QRect(220, 20, 100, 32));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(227, 70, 61, 20));
        Shear_wrt_orgin = new QPushButton(groupBox_5);
        Shear_wrt_orgin->setObjectName(QString::fromUtf8("Shear_wrt_orgin"));
        Shear_wrt_orgin->setGeometry(QRect(359, 20, 111, 32));
        Reflect_on_axis = new QPushButton(groupBox_5);
        Reflect_on_axis->setObjectName(QString::fromUtf8("Reflect_on_axis"));
        Reflect_on_axis->setGeometry(QRect(480, 20, 131, 32));
        X_axis = new QCheckBox(groupBox_5);
        X_axis->setObjectName(QString::fromUtf8("X_axis"));
        X_axis->setGeometry(QRect(610, 20, 121, 20));
        Y_axis = new QCheckBox(groupBox_5);
        Y_axis->setObjectName(QString::fromUtf8("Y_axis"));
        Y_axis->setGeometry(QRect(610, 40, 121, 20));
        Sx = new QDoubleSpinBox(groupBox_5);
        Sx->setObjectName(QString::fromUtf8("Sx"));
        Sx->setGeometry(QRect(210, 50, 62, 22));
        Sy = new QDoubleSpinBox(groupBox_5);
        Sy->setObjectName(QString::fromUtf8("Sy"));
        Sy->setGeometry(QRect(270, 50, 62, 22));
        Shx = new QDoubleSpinBox(groupBox_5);
        Shx->setObjectName(QString::fromUtf8("Shx"));
        Shx->setGeometry(QRect(360, 50, 62, 22));
        Shy = new QDoubleSpinBox(groupBox_5);
        Shy->setObjectName(QString::fromUtf8("Shy"));
        Shy->setGeometry(QRect(430, 50, 62, 22));
        NShx = new QCheckBox(groupBox_5);
        NShx->setObjectName(QString::fromUtf8("NShx"));
        NShx->setGeometry(QRect(360, 70, 31, 20));
        NShy = new QCheckBox(groupBox_5);
        NShy->setObjectName(QString::fromUtf8("NShy"));
        NShy->setGeometry(QRect(430, 70, 41, 20));
        Reflection_wrt_line = new QPushButton(groupBox_5);
        Reflection_wrt_line->setObjectName(QString::fromUtf8("Reflection_wrt_line"));
        Reflection_wrt_line->setGeometry(QRect(500, 60, 131, 32));
        Takep3 = new QPushButton(groupBox_5);
        Takep3->setObjectName(QString::fromUtf8("Takep3"));
        Takep3->setGeometry(QRect(640, 60, 51, 32));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(700, 430, 120, 91));
        Rotate_wrt_point = new QPushButton(groupBox_6);
        Rotate_wrt_point->setObjectName(QString::fromUtf8("Rotate_wrt_point"));
        Rotate_wrt_point->setGeometry(QRect(0, 20, 100, 32));
        Scale_wrt_point = new QPushButton(groupBox_6);
        Scale_wrt_point->setObjectName(QString::fromUtf8("Scale_wrt_point"));
        Scale_wrt_point->setGeometry(QRect(0, 50, 100, 32));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(830, 439, 311, 81));
        Taking_clipping_lines = new QPushButton(groupBox_7);
        Taking_clipping_lines->setObjectName(QString::fromUtf8("Taking_clipping_lines"));
        Taking_clipping_lines->setGeometry(QRect(0, 20, 100, 32));
        Clip_lines = new QPushButton(groupBox_7);
        Clip_lines->setObjectName(QString::fromUtf8("Clip_lines"));
        Clip_lines->setGeometry(QRect(0, 50, 100, 32));
        P1_of_clip_line = new QPushButton(groupBox_7);
        P1_of_clip_line->setObjectName(QString::fromUtf8("P1_of_clip_line"));
        P1_of_clip_line->setGeometry(QRect(100, 20, 100, 32));
        P2_clip_line = new QPushButton(groupBox_7);
        P2_clip_line->setObjectName(QString::fromUtf8("P2_clip_line"));
        P2_clip_line->setGeometry(QRect(100, 50, 100, 32));
        Cornor1 = new QPushButton(groupBox_7);
        Cornor1->setObjectName(QString::fromUtf8("Cornor1"));
        Cornor1->setGeometry(QRect(200, 20, 100, 32));
        Cornor2 = new QPushButton(groupBox_7);
        Cornor2->setObjectName(QString::fromUtf8("Cornor2"));
        Cornor2->setGeometry(QRect(200, 50, 100, 32));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(1150, 440, 211, 81));
        Polygon_clip = new QPushButton(groupBox_8);
        Polygon_clip->setObjectName(QString::fromUtf8("Polygon_clip"));
        Polygon_clip->setGeometry(QRect(0, 20, 100, 32));
        DDALine = new QPushButton(groupBox_8);
        DDALine->setObjectName(QString::fromUtf8("DDALine"));
        DDALine->setGeometry(QRect(0, 50, 100, 32));
        setvertex = new QPushButton(groupBox_8);
        setvertex->setObjectName(QString::fromUtf8("setvertex"));
        setvertex->setGeometry(QRect(100, 50, 100, 32));
        pushButton_2 = new QPushButton(groupBox_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 20, 100, 32));
        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(700, 520, 231, 80));
        setbezpoint = new QPushButton(groupBox_9);
        setbezpoint->setObjectName(QString::fromUtf8("setbezpoint"));
        setbezpoint->setGeometry(QRect(0, 20, 100, 32));
        clearbezpoint = new QPushButton(groupBox_9);
        clearbezpoint->setObjectName(QString::fromUtf8("clearbezpoint"));
        clearbezpoint->setGeometry(QRect(0, 50, 100, 32));
        drawBezierCurve = new QPushButton(groupBox_9);
        drawBezierCurve->setObjectName(QString::fromUtf8("drawBezierCurve"));
        drawBezierCurve->setGeometry(QRect(120, 20, 100, 32));
        Take4 = new QPushButton(centralWidget);
        Take4->setObjectName(QString::fromUtf8("Take4"));
        Take4->setGeometry(QRect(1340, 430, 51, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1685, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_grid->setText(QCoreApplication::translate("MainWindow", "show grid", nullptr));
        show_axis->setText(QCoreApplication::translate("MainWindow", "show axis", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "LINE", nullptr));
        DDA_line->setText(QCoreApplication::translate("MainWindow", "DDA", nullptr));
        Bresenham_line->setText(QCoreApplication::translate("MainWindow", "bresenham", nullptr));
        Draw_line->setText(QCoreApplication::translate("MainWindow", "draw line", nullptr));
        set_point2->setText(QCoreApplication::translate("MainWindow", "set point 2", nullptr));
        set_point1->setText(QCoreApplication::translate("MainWindow", "set point 1", nullptr));
        line_time->setText(QString());
        Draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "CIRCLE", nullptr));
        polar_circle->setText(QCoreApplication::translate("MainWindow", "POLAR", nullptr));
        bresenham_circle->setText(QCoreApplication::translate("MainWindow", "BRESENHAM", nullptr));
        cartesian_circle->setText(QCoreApplication::translate("MainWindow", "CARTESIAN", nullptr));
        mid_point_circle->setText(QCoreApplication::translate("MainWindow", "MIDPOINT", nullptr));
        set_center->setText(QCoreApplication::translate("MainWindow", "set center", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RADIUS", nullptr));
        draw_circle->setText(QCoreApplication::translate("MainWindow", "draw circle", nullptr));
        circle_time->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        set_Ellipse_center->setText(QCoreApplication::translate("MainWindow", "set center", nullptr));
        Polar_ellipse->setText(QCoreApplication::translate("MainWindow", "Polar", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "set a", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "set B", nullptr));
        draw_ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Ellipse", nullptr));
        bresenham_ellipse->setText(QCoreApplication::translate("MainWindow", "bresenham", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        Taking_points->setText(QCoreApplication::translate("MainWindow", "Taking Points", nullptr));
        Draw_Polygon->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        Take_points->setText(QCoreApplication::translate("MainWindow", "Take points", nullptr));
        scanline->setText(QCoreApplication::translate("MainWindow", "scanline fill", nullptr));
        flood_fill->setText(QCoreApplication::translate("MainWindow", "boundry fill", nullptr));
        timeValue->setText(QString());
        take_point_for_filling->setText(QCoreApplication::translate("MainWindow", "point", nullptr));
        flood_fill_2->setText(QCoreApplication::translate("MainWindow", "flood fill", nullptr));
        flood_fill_4->setText(QCoreApplication::translate("MainWindow", "flood fill 4", nullptr));
        boundry_fill_4->setText(QCoreApplication::translate("MainWindow", "boundry fill 4", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Transformations.", nullptr));
        Translation->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X            Y", nullptr));
        Rotate_polygon->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Degree", nullptr));
        Scale_wrt_orgin->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X            Y", nullptr));
        Shear_wrt_orgin->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        Reflect_on_axis->setText(QCoreApplication::translate("MainWindow", "Reflect on Axis", nullptr));
        X_axis->setText(QCoreApplication::translate("MainWindow", "on x axis", nullptr));
        Y_axis->setText(QCoreApplication::translate("MainWindow", "on Y axis", nullptr));
        NShx->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        NShy->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        Reflection_wrt_line->setText(QCoreApplication::translate("MainWindow", "Reflection wrt line", nullptr));
        Takep3->setText(QCoreApplication::translate("MainWindow", "p1", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "with respect to point", nullptr));
        Rotate_wrt_point->setText(QCoreApplication::translate("MainWindow", "Rotation ", nullptr));
        Scale_wrt_point->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Line clipping", nullptr));
        Taking_clipping_lines->setText(QCoreApplication::translate("MainWindow", "Take Line", nullptr));
        Clip_lines->setText(QCoreApplication::translate("MainWindow", "Clip lines", nullptr));
        P1_of_clip_line->setText(QCoreApplication::translate("MainWindow", "P1 for clip line", nullptr));
        P2_clip_line->setText(QCoreApplication::translate("MainWindow", "P2 for clip line", nullptr));
        Cornor1->setText(QCoreApplication::translate("MainWindow", "cornor 1", nullptr));
        Cornor2->setText(QCoreApplication::translate("MainWindow", "Cornor 2", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Polygon clipping", nullptr));
        Polygon_clip->setText(QCoreApplication::translate("MainWindow", "Polygon Clip", nullptr));
        DDALine->setText(QCoreApplication::translate("MainWindow", "DDA edge", nullptr));
        setvertex->setText(QCoreApplication::translate("MainWindow", "set vertex", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "set point", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "curve", nullptr));
        setbezpoint->setText(QCoreApplication::translate("MainWindow", "set curve point", nullptr));
        clearbezpoint->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        drawBezierCurve->setText(QCoreApplication::translate("MainWindow", "draw ", nullptr));
        Take4->setText(QCoreApplication::translate("MainWindow", "p2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
