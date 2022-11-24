#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_show_grid_clicked();


    void point_with_colour(int x,int y,int c1,int c2,int c3);
    void on_show_axis_clicked();
    void  delay(int n);

    void on_Draw_line_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_set_center_clicked();

    void on_draw_circle_clicked();

    void on_set_Ellipse_center_clicked();

    void on_draw_ellipse_clicked();


    void on_Draw_Polygon_clicked();

    void on_Take_points_clicked();
    void draw_my_line(int x1,int x2,int y1,int y2,std::vector<int>&scan);
    void boundaryFillUtil(int x, int y,std:: vector<int> newColor, std::vector<int> edgeColor, int flag);
    void point2(int x,int y,int c1,int c2,int c3);
    void floodFillUtil(int x, int y,std:: vector<int> newColor, std::vector<int> inColor, int flag);


    void on_scanline_clicked();

    void on_flood_fill_clicked();

    void on_take_point_for_filling_clicked();

    void on_flood_fill_2_clicked();

    void on_flood_fill_4_clicked();

    void on_boundry_fill_4_clicked();
    void polygonDraw();

    void on_Translation_clicked();

    void on_Rotate_polygon_clicked();

    void on_Scale_wrt_orgin_clicked();

    void on_Shear_wrt_orgin_clicked();

    void on_Reflect_on_axis_clicked();

    void on_Reflection_wrt_line_clicked();

    void on_Rotate_wrt_point_clicked();

    void on_Scale_wrt_point_clicked();

    void on_Taking_clipping_lines_clicked();

    void on_Clip_lines_clicked();

    void on_P1_of_clip_line_clicked();

    void on_P2_clip_line_clicked();
    void DDAline(int r, int g, int b);
    void cpoint(int x,int y, int r=255, int g=255, int b=0);
    void cohenSutherlandClip(int x1, int y1,int x2, int y2);

    void on_Cornor1_clicked();

    void on_Cornor2_clicked();
    void draw_Window();
    int computeCode(int xa, int ya);

    void on_Polygon_clip_clicked();
    void suthHodgClip();
    void clip(int x1, int y1, int x2, int y2);
    int x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    int  y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    void poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b);
    void on_DDALine_clicked();
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void initEdgeTable();
    void on_setvertex_clicked();



    void on_setbezpoint_clicked();

    void on_clearbezpoint_clicked();

    void on_drawBezierCurve_clicked();

    void on_pushButton_2_clicked();

    void on_Takep3_clicked();

    void on_Take4_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2,p3,p4;
    QPoint cp1,cp2;
    QPoint r1,r2;
    //void point(int x,int y, int r, int g, int b);
    void point(int,int);
};

#endif // MAINWINDOW_H
