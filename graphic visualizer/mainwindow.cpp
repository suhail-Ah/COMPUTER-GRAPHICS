#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <chrono>
#include <cmath>

#define maxHt 1800
#define maxWd 1000
#define maxVer 10000
#define fwidth 600
#define fheight 600

using namespace std;
using namespace std::chrono;
int gridsize=1;
std::vector<std::pair<int,int> > vertex_list;

QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//delay function to introduce animation while drawing
void MainWindow::delay(int n) {
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
//
int gridSize;
// Get x-corrdinate of cell given pixel
int getXCoordinate(int px) {
    int width = img.width();
    int midx = (width/(2 * gridSize)) * gridSize;

    if (px >= midx && px <= midx + gridSize)
        return 0;

    if (px >= width/2)
        return (px - midx - gridSize)/gridSize + 1;

    return -((midx - px)/gridSize + 1);
}

// Get y-coordinate of cell given pixel
int getYCoordinate(int py) {
    int height = img.height();
    int midy = (height/(2 * gridSize)) * gridSize;

    if(py >= midy && py <= midy + gridSize)
        return 0;

    if(py >= height/2)
        return -((py - midy - gridSize)/gridSize + 1);

    return (midy - py)/gridSize + 1;
}

// Given x-coordinate, get pixel
int toXPixel(int x) {
    int width = img.width();
    int midx = (width/(2 * gridSize)) * gridSize;
    return midx + x * gridSize;
}

// Given y-coordinate, get pixel
int toYPixel(int y) {
    int height = img.height();
    int midy = (height/(2 * gridSize)) * gridSize;
    return midy - y * gridSize;
}





void MainWindow::point(int x,int y)
{
    if(ui->show_grid->isChecked())
        {
         int k = ui->grid_size->value();
         int i=x/k;
         int j=y/k;
         i*=k;
         j*=k;
         for(int m=i+1;m<i+k;m++)
         {

             for(int n=j+1;n<j+k;n++)

                 img.setPixel(m,n,qRgb(0,225,0));

         }
    }

    img.setPixel(x,y,qRgb(255,255,0));
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::showMousePosition(QPoint &pos)
{
   int i=pos.x();
   int j=pos.y();

   // ui->mouse_movement->setText(" X : "+QString::number(i)+", Y : "+QString::number(j));

   ui->mouse_movement->setText(" X : "+QString::number(getXCoordinate(i))+", Y : "+QString::number(getYCoordinate(j)));
}
void MainWindow::Mouse_Pressed()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    point(ui->frame->x,ui->frame->y);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);

}





//line algorithms




class MyLine{
public:
    std::pair<int,int>p1;
    std::pair<int,int>p2;

};
MyLine myline;
void MainWindow::on_set_point1_clicked()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    myline.p1.first=getXCoordinate(ui->frame->x);
    myline.p1.second=getYCoordinate(ui->frame->y);
}
void MainWindow::on_set_point2_clicked()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    myline.p2.first=getXCoordinate(ui->frame->x);
    myline.p2.second=getYCoordinate(ui->frame->y);
}
void MainWindow::point_with_colour(int x,int y,int c1,int c2,int c3)
{
        if(ui->show_grid->isChecked())
            {
             int k = ui->grid_size->value();
             int i=x/k;
             int j=y/k;
             i*=k;
             j*=k;
             for(int m=i+1;m<i+k;m++){

                 for(int n=j+1;n<j+k;n++)

                     img.setPixel(m,n,qRgb(c1,c2,c3));

             }
        }

        img.setPixel(x,y,qRgb(c1,c2,c3));
        ui->frame->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_Draw_line_clicked()
{
   if(ui->DDA_line->isChecked())
   {
    int x1 = myline.p1.first, x2 = myline.p2.first;
    int y1 = myline.p1.second, y2 = myline.p2.second;
    auto start = high_resolution_clock::now();
     float x = x1, y = y1, Dx, Dy;
    int dx = abs(x2 - x1), dy = abs(y2 - y1), steps;

    // If the line is vertical
    if (dy == 0) {
        Dy = 0;
        Dx = 1;
        steps = abs(dx);
    }
    else if (dx > dy) {
        Dx = 1;
        Dy = float(dy)/float(dx);
        steps = abs(dx);
    }
    else {
        Dx = float(dx)/float(dy);
        Dy = 1;
        steps = abs(dy);
    }

    // If the difference in x-coordinates is negative
    if (x1 > x2)
        Dx *= -1;

    // If the difference in y-coordinates is negative
    if (y1 > y2)
        Dy *= -1;

    auto color = start - start;

    for (int k = 0; k <= steps; k++)
    {
        int i = floor(x + 0.5), j = floor(y + 0.5);

        auto start1 = high_resolution_clock::now();
        point(toXPixel(i), toYPixel(j));
         delay(10);
        auto stop1 = high_resolution_clock::now();

        color += stop1 - start1;

        x += Dx;
        y += Dy;
    }

    auto stop = high_resolution_clock::now();
    // Subtracting the time taken to color the pixel
   auto duration = duration_cast<microseconds>(stop - start - color);
   ui->line_time->setText (QString::number(duration.count()) + " microseconds");
   ui->frame->setPixmap(QPixmap::fromImage(img));

   }

   else if(ui->Bresenham_line->isChecked())
   {
    int x0 = myline.p1.first, xn = myline.p2.first;
    int y0 = myline.p1.second, yn = myline.p2.second;

    auto start = high_resolution_clock::now();
     int Dx = abs(xn - x0), Dy = abs(yn - y0);
    // If the difference between the x-coordinates is negative
    // If the difference between the y-coordinates is negative
    int ix = (x0 > xn ? -1: 1), iy = (y0 > yn ? -1: 1);
    bool flag = true;

    int x = x0, y = y0;
    if (Dy > Dx) {
        std::swap (x, y);
        std::swap (Dx, Dy);
        std::swap (ix, iy);
        flag = false;
    }

    int p = 2*Dy - Dx, ip1 = 2*Dy, ip2 = 2*Dy - 2*Dx;
    auto color = start - start;

    for (int i = 0; i <= Dx; i++)
    {
        if (flag) {
            auto start1 = high_resolution_clock::now();
            point(toXPixel(x), toYPixel(y));
            auto stop1 = high_resolution_clock::now();

            color += stop1 - start1;
        }
        else {
            auto start1 = high_resolution_clock::now();
            point(toXPixel(y), toYPixel(x));
            auto stop1 = high_resolution_clock::now();

            color += stop1 - start1;
        }

        if (p < 0)
            p += ip1;
        else {
            p += ip2;
            y += iy;
        }

        x += ix;
    }

    auto stop = high_resolution_clock::now();
    // Subtracting the time taken to color the pixel
    auto duration = duration_cast<microseconds>(stop - start - color);
    ui->line_time->setText (QString::number(duration.count()) + " microseconds");
    ui->frame->setPixmap(QPixmap::fromImage(img));
     }

}

void MainWindow::on_show_grid_clicked()
{
    int i,j,k=ui->grid_size->value();
    gridSize=k;
    int num=0;
        if(ui->show_grid->isChecked()){

            for(i=0,num;i<=img.width();i+=k,num++){

                for(j=0;j<=img.height();j++)

                    if(num%10==0)
                    {
                        img.setPixel(j,i,qRgb(255, 0, 0));
                    }
                else
                    {img.setPixel(j,i,qRgb(0, 0, 0));}

            }
          num=0;
            for(i=0,num;i<=img.height();i+=k,num++){

                for(j=0;j<=img.width();j++)

                    if(num%10==0)
                    {
                        img.setPixel(i,j,qRgb(255, 0, 0));
                    }
                else
                    {img.setPixel(i,j,qRgb(0, 0, 0));}

            }

            ui->frame->setPixmap(QPixmap::fromImage(img));

        }

        else{

            for(i=0;i<=img.width();i++){

                for(j=0;j<=img.height();j++)

                    img.setPixel(j,i,qRgb(0,0,0));

            }

            for(i=0;i<=img.height();i++){

                for(j=0;j<=img.width();j++)

                    img.setPixel(i,j,qRgb(0,0,0));

            }

            ui->frame->setPixmap(QPixmap::fromImage(img));

        }
}

void MainWindow::on_show_axis_clicked()
{
        //ui->x_axis->show();
            //ui->y_axis->show();
            int k=img.width();
            k=k/2;
            int gridSize=ui->grid_size->value();
            for(int j=0;j<=img.height() ;j+=gridSize)
            {
                point_with_colour(k,j,0,225,225);
            }

            k=img.height();
            k=k/2;
            for(int i=0;i<=img.width() ;i+=gridSize)
            {

                point_with_colour(i,k,0,225,225);

            }
             ui->frame->setPixmap(QPixmap::fromImage(img));

}

class Circle{
public:
    pair<int,int> center;
    int radius;
};


Circle myCricle;
void MainWindow::on_set_center_clicked()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    myCricle.center.first=getXCoordinate(ui->frame->x);
    myCricle.center.second=getYCoordinate(ui->frame->y);

}

void MainWindow::on_draw_circle_clicked()
{
    myCricle.radius=ui->radius_of_circle->value();
    if(ui->polar_circle->isChecked())
    {
            int cx = myCricle.center.first, cy =myCricle.center.second;
            int r = myCricle.radius;

            auto start = high_resolution_clock::now();
            auto color = start - start;

            for (int i = 0; i <= 360; i++)
            {
                double theta = i*(M_PI/180.0);
                float x = cx + r*cos(theta);
                int ix = floor(x + 0.5);
                float y = cy + r*sin(theta);
                int iy = floor(y + 0.5);

                auto start1 = high_resolution_clock::now();
                point_with_colour(toXPixel(ix), toYPixel(iy), 66, 135, 245);
                delay(10);
                auto stop1 = high_resolution_clock::now();
                color += stop1 - start1;
            }

            auto stop = high_resolution_clock::now();
            // Subtracting the time taken to color the pixel
            auto duration = duration_cast<microseconds>(stop - start - color);
            ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
            ui->frame->setPixmap(QPixmap::fromImage(img));
   }
    if(ui->bresenham_circle->isChecked())
    {
            int cx = myCricle.center.first, cy =myCricle.center.second;
            int r = myCricle.radius;

            auto start = high_resolution_clock::now();
            auto color = start - start;
            int d=3-(2*r);
            int x=0;
            int y=r;
            auto start1 = high_resolution_clock::now();
            point_with_colour(toXPixel(cx+x), toYPixel(cy+y), 214, 11, 11);
            point_with_colour(toXPixel(cx-x), toYPixel(cy+y), 214, 11, 11);
            point_with_colour(toXPixel(cx+x), toYPixel(cy-y), 214, 11, 11);
            point_with_colour(toXPixel(cx-x), toYPixel(cy-y), 214, 11, 11);
            point_with_colour(toXPixel(cx+y), toYPixel(cy+x), 214, 11, 11);
            point_with_colour(toXPixel(cx-y), toYPixel(cy+x), 214, 11, 11);
            point_with_colour(toXPixel(cx+y), toYPixel(cy-x), 214, 11, 11);
            point_with_colour(toXPixel(cx-y), toYPixel(cy-x), 214, 11, 11);
            delay(150);
            auto stop1 = high_resolution_clock::now();
            color += stop1 - start1;

            while(x<=y)
            {

                if(d>0)
                {

                    d=d+ (4*(x-y))+10;
                    y--;
                }
                else
                {
                    d=d+(4*x)+6;
                }
                 x++;
                 auto start1 = high_resolution_clock::now();
                point_with_colour(toXPixel(cx+x), toYPixel(cy+y), 214, 11, 11);
                point_with_colour(toXPixel(cx-x), toYPixel(cy+y), 214, 11, 11);
                point_with_colour(toXPixel(cx+x), toYPixel(cy-y), 214, 11, 11);
                point_with_colour(toXPixel(cx-x), toYPixel(cy-y), 214, 11, 11);
                point_with_colour(toXPixel(cx+y), toYPixel(cy+x), 214, 11, 11);
                point_with_colour(toXPixel(cx-y), toYPixel(cy+x), 214, 11, 11);
                point_with_colour(toXPixel(cx+y), toYPixel(cy-x), 214, 11, 11);
                point_with_colour(toXPixel(cx-y), toYPixel(cy-x), 214, 11, 11);
                delay(150);
                auto stop1 = high_resolution_clock::now();
                color += stop1 - start1;
            }



            auto stop = high_resolution_clock::now();
            // Subtracting the time taken to color the pixel
            auto duration = duration_cast<microseconds>(stop - start - color);
            ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
            ui->frame->setPixmap(QPixmap::fromImage(img));
   }
    if(ui->mid_point_circle->isChecked())
    {
            int cx = myCricle.center.first, cy =myCricle.center.second;
            int r = myCricle.radius;

            auto start = high_resolution_clock::now();
            auto color = start - start;
            double d =(1.25*r);
            int x=0;
            int y=r;
            while(x<=y)
            {
                auto start1 = high_resolution_clock::now();
                //int left=cx+x,right=cy+y;
                point_with_colour(toXPixel(cx+x), toYPixel(cy+y), 214, 11, 11);
                point_with_colour(toXPixel(cx-x), toYPixel(cy+y), 214, 11, 11);
                point_with_colour(toXPixel(cx+x), toYPixel(cy-y), 214, 11, 11);
                point_with_colour(toXPixel(cx-x), toYPixel(cy-y), 214, 11, 11);
                point_with_colour(toXPixel(cx+y), toYPixel(cy+x), 214, 11, 11);
                point_with_colour(toXPixel(cx-y), toYPixel(cy+x), 214, 11, 11);
                point_with_colour(toXPixel(cx+y), toYPixel(cy-x), 214, 11, 11);
                point_with_colour(toXPixel(cx-y), toYPixel(cy-x), 214, 11, 11);
                delay(150);
                auto stop1 = high_resolution_clock::now();
                color += stop1 - start1;
                if(int(d)>0)
                {

                    d=d+ (2*(x-y))+5;
                    x++;
                    y--;
                }
                else
                {

                    d=d+(2*x)+3;
                    x++;
                }
            }



            auto stop = high_resolution_clock::now();
            // Subtracting the time taken to color the pixel
            auto duration = duration_cast<microseconds>(stop - start - color);
            ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
            ui->frame->setPixmap(QPixmap::fromImage(img));
   }
    if(ui->cartesian_circle->isChecked())
        {
                int cx = myCricle.center.first, cy =myCricle.center.second;
                int r = myCricle.radius;

                auto start = high_resolution_clock::now();
                auto color = start - start;
                int x=0;
                double y;
                while((x)<=r)
                {
                    y=sqrt((r*r)-(x*x));
                    int yy=int(y+0.5);
                    auto start1 = high_resolution_clock::now();
                    //int left=cx+x,right=cy+y;
                    point_with_colour(toXPixel(cx+x), toYPixel(cy+yy), 214, 11, 11);
                    point_with_colour(toXPixel(cx-x), toYPixel(cy+yy), 214, 11, 11);
                    point_with_colour(toXPixel(cx+x), toYPixel(cy-yy), 214, 11, 11);
                    point_with_colour(toXPixel(cx-x), toYPixel(cy-yy), 214, 11, 11);

                    delay(150);
                    auto stop1 = high_resolution_clock::now();
                    color += stop1 - start1;
                    x++;
                }



                auto stop = high_resolution_clock::now();
                // Subtracting the time taken to color the pixel
                auto duration = duration_cast<microseconds>(stop - start - color);
                ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
                ui->frame->setPixmap(QPixmap::fromImage(img));
       }

}


class Ellipse{
public:
    pair<int,int> center;
    int a,b;
};
Ellipse myEllipse;

void MainWindow::on_set_Ellipse_center_clicked()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    myEllipse.center.first=getXCoordinate(ui->frame->x);
    myEllipse.center.second=getYCoordinate(ui->frame->y);
}


void MainWindow::on_draw_ellipse_clicked()
{

    myEllipse.a=ui->set_A->value();
    myEllipse.b=ui->set_B->value();
    if(ui->Polar_ellipse->isChecked())
    {

                int cx = myEllipse.center.first, cy =myEllipse.center.second;
                int a = myEllipse.a;
                int b=myEllipse.b;

                auto start = high_resolution_clock::now();
                auto color = start - start;

                for (int i = 0; i <= 360; i++)
                {

                    double theta = i*(M_PI/180.0);
                    float x = cx + a*cos(theta);
                    int ix = floor(x + 0.5);
                    float y = cy + b*sin(theta);
                    int iy = floor(y + 0.5);

                    auto start1 = high_resolution_clock::now();
                    point_with_colour(toXPixel(ix), toYPixel(iy), 19, 237, 55);
                    delay(10);
                    auto stop1 = high_resolution_clock::now();
                    color += stop1 - start1;
                }

                auto stop = high_resolution_clock::now();
                // Subtracting the time taken to color the pixel
                auto duration = duration_cast<microseconds>(stop - start - color);
                ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
                ui->frame->setPixmap(QPixmap::fromImage(img));


    }
    if(ui->bresenham_ellipse->isChecked())
    {

//        void midptellipse(int rx, int ry,
//                        int xc, int yc)
//        {
            int xc=myEllipse.center.first;
            int yc=myEllipse.center.second;
            int rx=myEllipse.a;
            int ry=myEllipse.b;
            float dx, dy, d1, d2, x, y;
            x = 0;
            y = ry;


            d1 = (ry * ry) - (rx * rx * ry) +
                            (0.25 * rx * rx);
            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;

            auto start = high_resolution_clock::now();
            auto color = start - start;

            // For region 1
            while (dx < dy)
            {

                // Print points based on 4-way symmetry
                auto start1 = high_resolution_clock::now();
                point_with_colour(toXPixel(x+xc), toYPixel(y+yc), 19, 237, 55);
                point_with_colour(toXPixel(-x+xc), toYPixel(y+yc), 19, 237, 55);
                point_with_colour(toXPixel(x+xc), toYPixel(-y+yc), 19, 237, 55);
                point_with_colour(toXPixel(-x+xc), toYPixel(-y+yc), 19, 237, 55);
                delay(10);
                auto stop1 = high_resolution_clock::now();
                color += stop1 - start1;

                // Checking and updating value of
                // decision parameter based on algorithm
                if (d1 < 0)
                {
                    x++;
                    dx = dx + (2 * ry * ry);
                    d1 = d1 + dx + (ry * ry);
                }
                else
                {
                    x++;
                    y--;
                    dx = dx + (2 * ry * ry);
                    dy = dy - (2 * rx * rx);
                    d1 = d1 + dx - dy + (ry * ry);
                }
            }

            // Decision parameter of region 2
            d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
                ((rx * rx) * ((y - 1) * (y - 1))) -
                (rx * rx * ry * ry);

            // Plotting points of region 2
            while (y >= 0)
            {

                // Print points based on 4-way symmetry
                auto start1 = high_resolution_clock::now();
                point_with_colour(toXPixel(x+xc), toYPixel(y+yc), 19, 237, 55);
                point_with_colour(toXPixel(-x+xc), toYPixel(y+yc), 19, 237, 55);
                point_with_colour(toXPixel(x+xc), toYPixel(-y+yc), 19, 237, 55);
                point_with_colour(toXPixel(-x+xc), toYPixel(-y+yc), 19, 237, 55);
                delay(10);
                auto stop1 = high_resolution_clock::now();
                color += stop1 - start1;

                // Checking and updating parameter
                // value based on algorithm
                if (d2 > 0)
                {
                    y--;
                    dy = dy - (2 * rx * rx);
                    d2 = d2 + (rx * rx) - dy;
                }
                else
                {
                    y--;
                    x++;
                    dx = dx + (2 * ry * ry);
                    dy = dy - (2 * rx * rx);
                    d2 = d2 + dx - dy + (rx * rx);
                }
            }
            auto stop = high_resolution_clock::now();
            // Subtracting the time taken to color the pixel
            auto duration = duration_cast<microseconds>(stop - start - color);
            ui->circle_time->setText (QString::number(duration.count()) + " microseconds");
            ui->frame->setPixmap(QPixmap::fromImage(img));


    }
}

class Poly{
public:
    int n;
    int ymax,ymin;
    vector<pair<int,int>>cor;

    void set()
    {
        for(unsigned int i=0;i<cor.size();i++)
        {
            if(ymin>cor[i].second)
            {
                ymin=cor[i].second;
            }
            if(ymax<cor[i].second)
            {
                ymax=cor[i].second;
            }

        }
    }


};
Poly myPoly;

void MainWindow::on_Take_points_clicked()
{


        ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
        pair<int,int>temp;
        temp.first=getXCoordinate(ui->frame->x);
        temp.second=getYCoordinate(ui->frame->y);
        myPoly.cor.push_back(temp);




}
void MainWindow::point2(int x,int y,int c1,int c2,int c3)
{
    if(ui->show_grid->isChecked())
        {
         int k = ui->grid_size->value();
         int i=x/k;
         int j=y/k;
         i*=k;
         j*=k;
         for(int m=i+1;m<i+k;m++){

             for(int n=j+1;n<j+k;n++)

                 img.setPixel(m,n,qRgb(c1,c2,c3));

         }
    }

    img.setPixel(x,y,qRgb(255,255,0));
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
void MainWindow:: draw_my_line(int x1,int x2,int y1,int y2,vector<int>&scan)
{

        float x = x1, y = y1, Dx, Dy;
        int dx = abs(x2 - x1), dy = abs(y2 - y1), steps;
        if (dy == 0) {
            Dy = 0;
            Dx = 1;
            steps = abs(dx);
        }
        else if (dx > dy) {
            Dx = 1;
            Dy = float(dy)/float(dx);
            steps = abs(dx);
        }
        else {
            Dx = float(dx)/float(dy);
            Dy = 1;
            steps = abs(dy);
        }

        // If the difference in x-coordinates is negative
        if (x1 > x2)
            Dx *= -1;

        // If the difference in y-coordinates is negative
        if (y1 > y2)
            Dy *= -1;

        //auto color = start - start;

        for (int k = 0; k <= steps; k++)
        {
             int i = floor(x + 0.5), j = floor(y + 0.5);

             //scan[j].push_back(i);
             //9, 230, 49
             point2(toXPixel(i), toYPixel(j),scan[0],scan[1],scan[2]);
             delay(10);

              x += Dx;
              y += Dy;
        }

       ui->frame->setPixmap(QPixmap::fromImage(img));
 }

void MainWindow::on_Draw_Polygon_clicked()
{

    int n=myPoly.ymax-myPoly.ymin;
    vector<int>scan;
    scan.push_back(9);
    scan.push_back(230);
    scan.push_back(49);


    for(unsigned int i=0;i < myPoly.cor.size();i++)
    {
        if(i != (myPoly.cor.size())-1)
        {
            //draw(i,i+1)
            int  x1=myPoly.cor[i].first;
            int  y1=myPoly.cor[i].second;
            int  x2=myPoly.cor[i+1].first;
            int  y2=myPoly.cor[i+1].second;
            draw_my_line(x1,x2,y1,y2,scan);


        }
        else
        {

            int  x1=myPoly.cor[i].first;
            int  y1=myPoly.cor[i].second;
            int  x2=myPoly.cor[0].first;
            int  y2=myPoly.cor[0].second;
            draw_my_line(x1,x2,y1,y2,scan);


        }
    }

}

pair<int,int>pointInside;
void MainWindow::on_take_point_for_filling_clicked()
{
    ui->mouse_pressed->setText(" X : "+QString::number(getXCoordinate(ui->frame->x))+", Y : "+QString::number(getYCoordinate(ui->frame->y)));
    pair<int,int>temp;
    temp.first=getXCoordinate(ui->frame->x);
    temp.second=getYCoordinate(ui->frame->y);
    pointInside=temp;
}

auto temp=high_resolution_clock::now();
auto colorT=temp-temp;
void MainWindow::boundaryFillUtil(int x, int y, std::vector<int> newColor,std:: vector<int> edgeColor, int flag)
{
    if (toXPixel(x) > 699 || toXPixel(x) < 0 || toYPixel(y) > 699 || toYPixel(y) < 0)
        return;

    QRgb pixColor = img.pixel(toXPixel(x) + 1, toYPixel(y) + 1);

    vector<int> curColor;
    curColor.push_back(qRed(pixColor));
    curColor.push_back(qGreen(pixColor));
    curColor.push_back(qBlue(pixColor));

    int flag1 = 1, flag2 = 1;
    for (int i = 0; i < 3; i++) {
        if (curColor[i] != newColor[i])
            flag1 = 0;

        if (curColor[i] != edgeColor[i])
            flag2 = 0;
    }

    if (!flag1 && !flag2) {
        auto start1 = high_resolution_clock::now();
        point2(toXPixel(x), toYPixel(y), newColor[0], newColor[1], newColor[2]);
        delay(25);
        auto stop1 = high_resolution_clock::now();
        colorT += stop1 - start1;

        if (flag) boundaryFillUtil(x + 1, y + 1, newColor, edgeColor, flag);
        boundaryFillUtil(x + 1, y, newColor, edgeColor, flag);
        if (flag) boundaryFillUtil(x + 1, y - 1, newColor, edgeColor, flag);
        boundaryFillUtil(x, y - 1, newColor, edgeColor, flag);
        if (flag) boundaryFillUtil(x - 1, y - 1, newColor, edgeColor, flag);
        boundaryFillUtil(x - 1, y, newColor, edgeColor, flag);
        if (flag) boundaryFillUtil(x - 1, y + 1, newColor, edgeColor, flag);
        boundaryFillUtil(x, y + 1, newColor, edgeColor, flag);
    }
}

void MainWindow::on_flood_fill_clicked()
{
    vector<int> newColor;
    newColor.push_back(226);
    newColor.push_back(230);
    newColor.push_back(9);

    vector<int> edgeColor;
    edgeColor.push_back(9);
    edgeColor.push_back(230);
    edgeColor.push_back(49);

    int x = pointInside.first, y = pointInside.second;
    point_with_colour(toXPixel(x), toYPixel(y), 0, 0, 0);

    auto start = high_resolution_clock::now();
    colorT = start - start;
    boundaryFillUtil(x, y, newColor, edgeColor, 1);
    auto stop = high_resolution_clock::now();

    // Subtracting the time taken to color the pixel
    auto duration = duration_cast<microseconds>(stop - start - colorT);
    ui->timeValue->setText (QString::number(duration.count()) + " μs");

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::floodFillUtil(int x, int y, vector<int> newColor, vector<int> inColor, int flag)
{
    if (toXPixel(x) > 699 || toXPixel(x) < 0 || toYPixel(y) > 699 || toYPixel(y) < 0)
        return;

    QRgb pixColor = img.pixel(toXPixel(x) + 1, toYPixel(y) + 1);

    vector<int> curColor;
    curColor.push_back(qRed(pixColor));
    curColor.push_back(qGreen(pixColor));
    curColor.push_back(qBlue(pixColor));

    int flag2 = 1;

    for (int i = 0; i < 3; i++)
        if (curColor[i] != inColor[i])
            flag2 = 0;

    if (flag2) {
        auto start1 = high_resolution_clock::now();
        point2(toXPixel(x), toYPixel(y), newColor[0], newColor[1], newColor[2]);
        delay(25);
        auto stop1 = high_resolution_clock::now();
        colorT += stop1 - start1;

        if (flag) floodFillUtil(x + 1, y + 1, newColor, inColor, flag);
        floodFillUtil(x + 1, y, newColor, inColor, flag);
        if (flag) floodFillUtil(x + 1, y - 1, newColor, inColor, flag);
        floodFillUtil(x, y - 1, newColor, inColor, flag);
        if (flag) floodFillUtil(x - 1, y - 1, newColor, inColor, flag);
        floodFillUtil(x - 1, y, newColor, inColor, flag);
        if (flag) floodFillUtil(x - 1, y + 1, newColor, inColor, flag);
        floodFillUtil(x, y + 1, newColor, inColor, flag);
    }
}

void MainWindow::on_flood_fill_2_clicked()
{
    //245, 134, 7
    vector<int> newColor;
    newColor.push_back(245);
    newColor.push_back(134);
    newColor.push_back(7);

    vector<int> inColor;
    inColor.push_back(255);
    inColor.push_back(255);
    inColor.push_back(255);

    int x =pointInside.first, y = pointInside.second;
    point2(toXPixel(x), toYPixel(y), 255, 255, 255);

    auto start = high_resolution_clock::now();
    colorT = start - start;
    floodFillUtil(x, y, newColor, inColor, 1);
    auto stop = high_resolution_clock::now();

    // Subtracting the time taken to color the pixel
    auto duration = duration_cast<microseconds>(stop - start - colorT);
    ui->timeValue->setText (QString::number(duration.count()) + " μs");

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_flood_fill_4_clicked()
{
    vector<int> newColor;
        newColor.push_back(150);
        newColor.push_back(150);
        newColor.push_back(100);

        vector<int> inColor;
        inColor.push_back(255);
        inColor.push_back(255);
        inColor.push_back(255);

        int x = pointInside.first, y = pointInside.second;
        point2(toXPixel(x), toYPixel(y), 255, 255, 255);

        auto start = high_resolution_clock::now();
        colorT = start - start;
        floodFillUtil(x, y, newColor, inColor, 0);
        auto stop = high_resolution_clock::now();

        // Subtracting the time taken to color the pixel
        auto duration = duration_cast<microseconds>(stop - start - colorT);
        ui->timeValue->setText (QString::number(duration.count()) + " μs");

        ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_boundry_fill_4_clicked()
{
    vector<int> newColor;
    newColor.push_back(226);
    newColor.push_back(230);
    newColor.push_back(9);

    vector<int> edgeColor;
    edgeColor.push_back(9);
    edgeColor.push_back(230);
    edgeColor.push_back(49);

        int x = pointInside.first, y = pointInside.second;
        point2(toXPixel(x), toYPixel(y), 0, 0, 0);

        auto start = high_resolution_clock::now();
        colorT = start - start;
        boundaryFillUtil(x, y, newColor, edgeColor, 0);
        auto stop = high_resolution_clock::now();

        // Subtracting the time taken to color the pixel
        auto duration = duration_cast<microseconds>(stop - start - colorT);
        ui->timeValue->setText (QString::number(duration.count()) + " μs");

        ui->frame->setPixmap(QPixmap::fromImage(img));

}

void matmul(double trmatrix[3][3], int pt[3])
{
    int result[3];
    for (int i = 0; i < 3; i++)
    {
        result[i] = 0;
        for (int j = 0; j < 3; j++)
            result[i] += trmatrix[i][j] * pt[j];
    }

    for (int i = 0; i < 3; i++)
        pt[i] = result[i];
}


void MainWindow::poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b) {
    for(unsigned int i=0;i<vlist.size()-1;i++)
    {
        p1.setX(vlist[i].first); p1.setY(vlist[i].second);
        p2.setX(vlist[i+1].first); p2.setY(vlist[i+1].second);
        DDAline(r,g,b);
    }
}
void mat_mult(double a[3][3], int b[3], double res[3]){
    int i,j;
    for(i=0;i<3;i++){
        res[i]=0;
        for(j=0;j<3;j++)
            res[i]+=(a[i][j]*b[j]);
    }
}
void translation (int pt[3], double tx, double ty)
{
    double trmatrix[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    matmul(trmatrix, pt);
}

void MainWindow::polygonDraw() {
    int s = vertex_list.size();

    for (int i = 1; i < s; i++) {
        p1.setX(vertex_list[i].first);p1.setY(vertex_list[i].second);
        p2.setX(vertex_list[i - 1].first);p2.setY(vertex_list[i - 1].second);
        DDAline(240, 4, 4);
    }

    p1.setX(vertex_list[0].first);p1.setY(vertex_list[0].second);
    p2.setX(vertex_list[s - 1].first);p2.setY(vertex_list[s - 1].second);
    DDAline(240, 4, 4);
}

void MainWindow::on_Translation_clicked()
{
        double tx = ui->Tx->value();
        double ty = ui->Ty->value();
        int k = gridSize;

        std::vector<std::pair<int,int> > old_vertex = vertex_list;
        for(unsigned int i=0;i<vertex_list.size();i++)
        {
            old_vertex.push_back(vertex_list[i]);
        }

        tx*=k;
        ty*=k;
        ty=-ty;
        int i,len=vertex_list.size();

        // matrix for translation
        double mat[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};

        int coord[3];
        double res[3];
        for(i=0;i<len;i++)
        {
            coord[0]=vertex_list[i].first;
            coord[1]=vertex_list[i].second;
            coord[2]=1;
            mat_mult(mat,coord,res);
            vertex_list[i].first= res[0]/res[2];
            vertex_list[i].second= res[1]/res[2];
        }
        poly_draw(old_vertex,255,255,255);
        poly_draw(vertex_list,70, 130, 77);
}


void matmul2(double a[3][3], int b[3], double res[3]){
    int i, j;
    for(i = 0; i < 3; i++) {
        res[i] = 0;

        for(j = 0; j < 3; j++)
            res[i] += (a[i][j] * b[j]);
    }
}

void MainWindow::on_Rotate_polygon_clicked()
{
        int angle = ui->Degree->value();


        std::vector<std::pair<int,int> > old_vertex;
        for(unsigned int i=0;i<vertex_list.size();i++)
        {
            old_vertex.push_back(vertex_list[i]);
        }

        double dang=(double)angle*M_PI/180.0;
        double sinang=sin(dang);
        double cosang=cos(dang);

        //Point about which to be rotated
        int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
        int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

        int i,len=vertex_list.size();

        // matrix for rotation
        double mat[3][3]={{cosang,-sinang,0},{sinang,cosang,0},{0,0,1}};
        int coord[3];
        double res[3];
        for(i=0;i<len;i++)
        {
            coord[0]=vertex_list[i].first-piv_x;
            coord[1]=piv_y-vertex_list[i].second;
            coord[2]=1;
            mat_mult(mat,coord,res);
            vertex_list[i].first=res[0]/res[2]+piv_x;
            vertex_list[i].second=piv_y-res[1]/res[2];
        }

        poly_draw(old_vertex,255,255,255);
        poly_draw(vertex_list,70, 130, 77);
}



void MainWindow::on_Scale_wrt_orgin_clicked()
{
        double sx = ui->Sx->value();
        double sy = ui->Sy->value();
        gridsize = gridSize;

        std::vector<std::pair<int,int> > old_vertex;
        for(unsigned int i=0;i<vertex_list.size();i++)
        {
            old_vertex.push_back(vertex_list[i]);
        }

        //Point about which to be scaled
        int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
        int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

        int i,len=vertex_list.size();

        // matrix for scaling
        double mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
        int coord[3];
        double res[3];
        for(i=0;i<len;i++)
        {
            int* coord=(int*)malloc(3*sizeof(int));
            coord[0]=vertex_list[i].first-piv_x;
            coord[1]=piv_y-vertex_list[i].second;
            coord[2]=1;
            mat_mult(mat,coord,res);
            vertex_list[i].first=res[0]/res[2]+piv_x;
            vertex_list[i].second=piv_y-res[1]/res[2];

        }

        poly_draw(old_vertex,255,255,255);
        poly_draw(vertex_list,70, 130, 77);
}

void MainWindow::on_Shear_wrt_orgin_clicked()
{
        double shx = ui->Shx->value();
        double shy = ui->Shy->value();


        std::vector<std::pair<int,int> > old_vertex;
        for(unsigned int i=0;i<vertex_list.size();i++)
        {
            old_vertex.push_back(vertex_list[i]);
        }

        //Point about which to be scaled
        int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
        int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

        int i,len=vertex_list.size();

        // matrix for shearing
        double mat[3][3]={{1,shx,0},{shy,1,0},{0,0,1}};
        int coord[3];
        double res[3];
        for(i=0;i<len;i++)
        {
            coord[0]=vertex_list[i].first-piv_x;
            coord[1]=piv_y-vertex_list[i].second;
            coord[2]=1;
            mat_mult(mat,coord,res);
            vertex_list[i].first=res[0]/res[2]+piv_x;
            vertex_list[i].second=piv_y-res[1]/res[2];
        }
        poly_draw(old_vertex,255,255,255);
        poly_draw(vertex_list,70, 130, 77);
}




void MainWindow::on_Reflect_on_axis_clicked()
{

    if(ui->X_axis->isChecked())
   {        int i,len=vertex_list.size();
           poly_draw(vertex_list,255,255,255);
            for(i=0;i<len;i++)
            {

                int x1=getXCoordinate(vertex_list[i].first);
                int y1=getYCoordinate(vertex_list[i].second);

                vertex_list[i].first= toXPixel(x1);
                vertex_list[i].second=toYPixel(-y1);
            }
            poly_draw(vertex_list,0,0,255);
    }
    //reflection on y-axis
    if(ui->Y_axis->isChecked())
    {
        int i,len=vertex_list.size();
                   poly_draw(vertex_list,255,255,255);
                    for(i=0;i<len;i++)
                    {

                        int x1=getXCoordinate(vertex_list[i].first);
                        int y1=getYCoordinate(vertex_list[i].second);

                        vertex_list[i].first= toXPixel(-x1);
                        vertex_list[i].second=toYPixel(y1);
                    }
                    poly_draw(vertex_list,0,0,255);

    }

}

void MainWindow::on_Takep3_clicked()
{
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
}


void MainWindow::on_Take4_clicked()
{
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
}
void MainWindow::on_Reflection_wrt_line_clicked()
{
//        p1.setX(p3.x());
//        p1.setY(p3.y());
//        p2.setX(p4.x());
//        p2.setX(p4.y());
        DDAline(300,300,300);

        int i,len=vertex_list.size();

            double dx=p1.x()-p2.x();
            double dy=p1.y()-p2.y();

            double a=-dy;
            double b=dx;
            double c=p1.x()*dy-p1.y()*dx;

            for(i=0;i<len;i++)
            {
                int x1=vertex_list[i].first;
                int y1=vertex_list[i].second;

                vertex_list[i].first=(int)((double)x1-(double)(2*a*(a*x1+b*y1+c))/(double)((a*a+b*b)));
                vertex_list[i].second=(int)((double)y1-(double)(2*b*(a*x1+b*y1+c))/(double)((a*a+b*b)));
            }
            poly_draw(vertex_list,0,255,255);

    }

void MainWindow::on_Rotate_wrt_point_clicked()
{
    //translate to orgin
    int tx=pointInside.first;
    int ty=pointInside.second;

        for (int i = 0; i < (int)vertex_list.size(); i++)
        {
            int px = (vertex_list[i].first);
            int py = (vertex_list[i].second);
            int pt[3] = {px, py, 1};
            translation(pt, -tx, -ty);
            vertex_list[i] = make_pair((pt[0]),(pt[1]));
        }

    //rotate
        int angle = ui->Degree->value();
        double rad = (double)angle*M_PI/180.0;
        double sin_val = sin(rad);
        double cos_val = cos(rad);
        int coord[3] = {1, 1, 1};
        double mat[3][3] = {{cos_val, sin_val, 0}, {-sin_val, cos_val, 0}, {0, 0, 1}};
        double res[3];
        for (int i = 0; i < (int)vertex_list.size(); i++)
        {
            coord[0] = vertex_list[i].first ;
            coord[1] = vertex_list[i].second;
            matmul2(mat, coord, res);

            vertex_list[i].first = int(res[0] + 0.5);
            vertex_list[i].second =int(res[1] + 0.5);
        }

    //translate back
        for (int i = 0; i < (int)vertex_list.size(); i++)
        {
            int px = (vertex_list[i].first);
            int py = (vertex_list[i].second);
            int pt[3] = {px, py, 1};
            translation(pt, tx, ty);
            vertex_list[i] = make_pair((pt[0]),(pt[1]));
        }
        polygonDraw();

}

void MainWindow::on_Scale_wrt_point_clicked()
{
     //translate to orgin
    int tx=pointInside.first;
    int ty=pointInside.second;

        for (int i = 0; i < (int)myPoly.cor.size(); i++)
        {
            int px = (myPoly.cor[i].first);
            int py = (myPoly.cor[i].second);
            int pt[3] = {px, py, 1};
            translation(pt, -tx, -ty);
            myPoly.cor[i] = make_pair((pt[0]),(pt[1]));
        }

    // scale wrt orgin
        double sx = ui->Sx->value(), sy = ui->Sy->value();
        double mat[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1.0}};
        for (int i = 0; i < (int)myPoly.cor.size(); i++) {
            int px = myPoly.cor[i].first;
            int py = myPoly.cor[i].second;
            int pt[3] = {px, py, 1};
            matmul(mat, pt);
            myPoly.cor[i] = make_pair(pt[0],pt[1]);
        }

    //translate back
        for (int i = 0; i < (int)myPoly.cor.size(); i++)
        {
            int px = (myPoly.cor[i].first);
            int py = (myPoly.cor[i].second);
            int pt[3] = {px, py, 1};
            translation(pt,tx, ty);
            myPoly.cor[i] = make_pair((pt[0]),(pt[1]));
        }
        polygonDraw();

}
//====================scan line algo===========================================================
// polygon drawing

void MainWindow::on_DDALine_clicked()
{
    DDAline(70, 130, 77);
}
void MainWindow::on_setvertex_clicked()
{
    vertex_list.push_back(std::make_pair((ui->frame->x/gridsize)*gridsize+gridsize/2,(ui->frame->y/gridsize)*gridsize+gridsize/2));
    int i=vertex_list.size();
    if(i>=2)
    {
        storeEdgeInTable(vertex_list[i-2].first, vertex_list[i-2].second, vertex_list[i-1].first, vertex_list[i-1].second);//storage of edges in edge table.
        p1.setX(vertex_list[i-1].first);p1.setY(vertex_list[i-1].second);
        p2.setX(vertex_list[i-2].first);p2.setY(vertex_list[i-2].second);
        on_DDALine_clicked();
    }
}
typedef struct edgebucket
{
    int ymax;   //max y-coordinate of edge
    float xofymin;  //x-coordinate of lowest edge point updated only in aet
    float slopeinverse;
}EdgeBucket;

typedef struct edgetabletup
{
    // the array will give the scanline number
    // The edge table (ET) with edges entries sorted
    // in increasing y and x of the lower end

    int countEdgeBucket;    //no. of edgebuckets
    EdgeBucket buckets[maxVer];
}EdgeTableTuple;

EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple;
void MainWindow::initEdgeTable()
{
    int i;
    for (i=0; i<maxHt; i++)
    {
        EdgeTable[i].countEdgeBucket = 0;
    }

    ActiveEdgeTuple.countEdgeBucket = 0;
}

void insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    EdgeBucket temp;

    for (i = 1; i < ett->countEdgeBucket; i++)
    {
        temp.ymax = ett->buckets[i].ymax;
        temp.xofymin = ett->buckets[i].xofymin;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))
    {
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
        ett->buckets[j + 1].ymax = temp.ymax;
        ett->buckets[j + 1].xofymin = temp.xofymin;
        ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}

void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;

    insertionSort(receiver);
    (receiver->countEdgeBucket)++;
}

void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int ymaxTS,xwithyminTS, scanline;

    if (x2==x1)
    {
        minv=0.000000;
    }
    else
    {
    m = ((float)(y2-y1))/((float)(x2-x1));

    if (y2==y1)
        return;

    minv = (float)1.0/m;
    }

    if (y1>y2)
    {
        scanline=y2;
        ymaxTS=y1;
        xwithyminTS=x2;
    }
    else
    {
        scanline=y1;
        ymaxTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv);
}

void removeEdgeByYmax(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->countEdgeBucket; i++)
    {
        if (Tup->buckets[i].ymax == yy)
        {
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ )
                {
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax;
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->countEdgeBucket--;
            i--;
        }
    }
}

void updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;

    for (i=0; i<Tup->countEdgeBucket; i++)
    {
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
    }
}

void MainWindow::on_scanline_clicked()
{
    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;

    for (i=0; i<maxHt; i++)
    {
        for (j=0; j<EdgeTable[i].countEdgeBucket; j++)
        {
            storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].
                     ymax,EdgeTable[i].buckets[j].xofymin,
                    EdgeTable[i].buckets[j].slopeinverse);
        }

        removeEdgeByYmax(&ActiveEdgeTuple, i);

        insertionSort(&ActiveEdgeTuple);

        j = 0;
        FillFlag = 0;
        coordCount = 0;
        x1 = 0;
        x2 = 0;
        ymax1 = 0;
        ymax2 = 0;
        while (j<ActiveEdgeTuple.countEdgeBucket)
        {
            if (coordCount%2==0)
            {
                x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
                ymax1 = ActiveEdgeTuple.buckets[j].ymax;
                if (x1==x2)
                {
                    if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                    {
                        x2 = x1;
                        ymax2 = ymax1;
                    }

                    else
                    {
                        coordCount++;
                    }
                }

                else
                {
                        coordCount++;
                }
            }
            else
            {
                x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
                ymax2 = ActiveEdgeTuple.buckets[j].ymax;

                FillFlag = 0;
                if (x1==x2)
                {
                    if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                    {
                        x1 = x2;
                        ymax1 = ymax2;
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }
                }
                else
                {
                    coordCount++;
                    FillFlag = 1;
                }

            if(FillFlag)
            {
                    p1.setX(x1);p1.setY(i);
                    p2.setX(x2);p2.setY(i);
                    DDAline(200,200,200);
            }

        }

        j++;
    }
    updatexbyslopeinv(&ActiveEdgeTuple);
}

    vertex_list.clear();
    initEdgeTable();
}



//====================clipping algo==============================================================

class ClipLine{
    public:
    pair<int,int>p1;
    pair<int,int>p2;
};
vector<ClipLine>ClipLines;

void MainWindow::cpoint(int x,int y, int r, int g, int b)
{

    if(ui->show_grid->isChecked())
        {
         int k = ui->grid_size->value();
         int i=x/k;
         int j=y/k;
         i*=k;
         j*=k;
         for(int m=i+1;m<i+k;m++){

             for(int n=j+1;n<j+k;n++)

                 img.setPixel(m,n,qRgb(r,g,b));

         }
    }

//    img.setPixel(x,y,qRgb(255,255,0));
//    ui->frame->setPixmap(QPixmap::fromImage(img));
//    //int r=255, int g=255, int b=0
//    if(gridsize == 1) img.setPixel(x,y,qRgb(r,g,b));
//    else {
//        x = (x/gridsize)*gridsize;
//        y = (y/gridsize)*gridsize;
//        for(int i=x+1;i <  x + gridsize;i++) {
//            for(int j=y+1;j < y + gridsize;j++) {
//                img.setPixel(i,j,qRgb(r,g,b));
//            }
//        }
//    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::DDAline(int r, int g, int b)
{
    double x1 = p1.x()/gridsize;
    double y1 = p1.y()/gridsize;
    double x2 = p2.x()/gridsize;
    double y2 = p2.y()/gridsize;
    double xinc, yinc, step;
    double slope = fabs(y2-y1)/fabs(x2-x1);
    if(slope  <= 1.00) {
        xinc = 1;
        yinc = slope;
        step = fabs(x2 - x1);
    } else {
        xinc = 1/slope;
        yinc = 1;
        step = fabs(y2 - y1);
    }
    if(x1 > x2) xinc *= -1;
    if(y1 > y2) yinc *= -1;
    double x = x1*gridsize + gridsize/2;
    double y = y1*gridsize + gridsize/2;
    for(int i=0;i<=step;i++) {
        cpoint(x,y,r,g,b);
        delay(2);
        x += xinc * gridsize;
        y += yinc * gridsize;
    }
}
pair<int,int>clipP1;
pair<int,int>clipP2;
void MainWindow::on_P1_of_clip_line_clicked()
{
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
}
void MainWindow::on_P2_clip_line_clicked()
{      p2.setX(ui->frame->x);
       p2.setY(ui->frame->y);
}

void MainWindow::on_Taking_clipping_lines_clicked()
{
    ClipLine temp;
    temp.p1.first=p1.x();
    temp.p1.second=p1.y();
    temp.p2.first=p2.x();
    temp.p2.second=p2.y();
    ClipLines.push_back(temp);
    DDAline(450,450,450);

}

int clipper_points[4][2];

void MainWindow::on_Cornor1_clicked()
{
    cp1.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
    cp1.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);
}


void MainWindow::on_Cornor2_clicked()
{
        cp2.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
        cp2.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);

        clipper_points[0][0]=cp1.x();
        clipper_points[0][1]=cp1.y();
        clipper_points[1][0]=cp1.x();
        clipper_points[1][1]=cp2.y();
        clipper_points[2][0]=cp2.x();
        clipper_points[2][1]=cp2.y();
        clipper_points[3][0]=cp2.x();
        clipper_points[3][1]=cp1.y();

        draw_Window();

}
void MainWindow::draw_Window()
{
    p1.setX(clipper_points[0][0]);
    p1.setY(clipper_points[0][1]);
    p2.setX(clipper_points[1][0]);
    p2.setY(clipper_points[1][1]);
    DDAline(9,230,49);

    p1.setX(clipper_points[1][0]);
    p1.setY(clipper_points[1][1]);
    p2.setX(clipper_points[2][0]);
    p2.setY(clipper_points[2][1]);
    DDAline(9,230,49);

    p1.setX(clipper_points[2][0]);
    p1.setY(clipper_points[2][1]);
    p2.setX(clipper_points[3][0]);
    p2.setY(clipper_points[3][1]);
    DDAline(9,230,49);

    p1.setX(clipper_points[3][0]);
    p1.setY(clipper_points[3][1]);
    p2.setX(clipper_points[0][0]);
    p2.setY(clipper_points[0][1]);
    DDAline(9,230,49);
}

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000


// Function to compute region code for a point(x, y)
int MainWindow::computeCode(int xa, int ya)
{
    int x_min=cp1.x(),x_max=cp2.x(),y_min=cp1.y(),y_max=cp2.y();

    // initialized as being inside
        int code = INSIDE;
        if (xa < x_min)       // to the left of rectangle
            code |= LEFT;
        else if (xa > x_max)  // to the right of rectangle
            code |= RIGHT;
        if (ya < y_min)       // below the rectangle
            code |= BOTTOM;
        else if (ya > y_max)  // above the rectangle
            code |= TOP;

        return code;
}



void MainWindow::cohenSutherlandClip(int x1, int y1,int x2, int y2)
{
    int x_min=clipper_points[0][0],x_max=clipper_points[2][0],y_min=clipper_points[0][1],y_max=clipper_points[2][1];

    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {

        if ((code1 == 0) && (code2 == 0))
        {
            accept =true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            int x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = x1 + (int)((double)(x2 - x1) *(double)(y_max - y1) /(double)(y2 - y1));
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (int)((double)(x2 - x1) * (double)(y_min - y1) / (double)(y2 - y1));
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (int)((double)(y2 - y1) * (double)(x_max - x1) / (double)(x2 - x1));
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (int)((double)(y2 - y1) * (double)(x_min - x1) / (double)(x2 - x1));
                x = x_min;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {

        p1.setX(x1);
        p1.setY(y1);

        p2.setX(x2);
        p2.setY(y2);

        DDAline(9,230,49);
        draw_Window();
    }
    else
    {

        draw_Window();
    }

}
void MainWindow::on_Clip_lines_clicked()
{
    for(unsigned int i=0;i<ClipLines.size();i++)
     {

     p1.setX(ClipLines[i].p1.first);
     p1.setY(ClipLines[i].p1.second);

     p2.setX(ClipLines[i].p2.first);
     p2.setY(ClipLines[i].p2.second);
     DDAline(0,0,0);
     cohenSutherlandClip(p1.x(),p1.y(),p2.x(),p2.y());
    }
}





int MainWindow::x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (x3-x4) -
              (x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int retx=num/den;
    return retx;
}

// Returns y-value of point of intersectipn of
// two lines
int MainWindow:: y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (y3-y4) -
              (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int rety= (ui->frame->height()-num/den+1);
    return rety;
}





// edge of clipping area
void MainWindow:: clip(int x1, int y1, int x2, int y2)
{
    int poly_size=vertex_list.size()-1;
    int new_poly_size = 0;

    std::vector<std::pair<int,int> > new_points;

    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = vertex_list[i].first, iy = vertex_list[i].second;
        int kx = vertex_list[k].first, ky = vertex_list[k].second;

        // Calculating position of first and second point

        int i_pos,k_pos;
        if(x2==x1 && ix>x1) i_pos=1;
        else if(x2==x1 && ix<x1) i_pos=-1;
        else if(y2==y1 && iy<y1) i_pos=1;
        else i_pos=-1;

        if(x2==x1 && kx>x1) k_pos=1;
        else if(x2==x1 && kx<x1) k_pos=-1;
        else if(y2==y1 && ky<y1) k_pos=1;
        else k_pos=-1;

        if(y1>y2||x1>x2)
        {
            i_pos=(-1)*i_pos;
            k_pos=(-1)*k_pos;
        }

        // Case 1 : When both points are inside
        if (i_pos >= 0  && k_pos >= 0)
        {
            //Only second point is added
            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 2: When only first point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            // Point of intersection with edge
            // and the second point is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;

            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 3: When only second point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            //Only point of intersection with edge is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;
        }

        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }

    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    vertex_list.clear();
    for (int i = 0; i < new_points.size(); i++)
    {
        vertex_list.push_back(new_points[i]);
    }
   vertex_list.push_back(new_points[0]);
}


// Implements Sutherland–Hodgman algorithm
void MainWindow::suthHodgClip()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(unsigned int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }
    int clipper_size=4;
    //i and k are two consecutive indexes
    for (int i=0; i<clipper_size; i++)
    {
        int k = (i+1) % clipper_size;

        // We pass the current array of vertices, it's size
        // and the end points of the selected clipper line
        clip(clipper_points[i][0],clipper_points[i][1], clipper_points[k][0],clipper_points[k][1]);
    }

    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,255,255,255);
    draw_Window();
}
void MainWindow::on_Polygon_clip_clicked()
{
    suthHodgClip();
}


//=========================curve================================
//==============================================================
//==============================================================



std::vector<std::pair<int,int> > BezList;

void MainWindow::on_setbezpoint_clicked()
{
    int k=gridsize;
    int x=((ui->frame->x)/k)*k+k/2;
    int y=((ui->frame->y)/k)*k+k/2;
    BezList.push_back(std::make_pair(x,y));

    int i=BezList.size();

    if(BezList.size()>1)
    {
        storeEdgeInTable(BezList[i-2].first, BezList[i-2].second, BezList[i-1].first, BezList[i-1].second);//storage of edges in edge table.

        p1.setX(BezList[BezList.size()-1].first);
        p2.setX(BezList[BezList.size()-2].first);

        p1.setY(BezList[BezList.size()-1].second);
        p2.setY(BezList[BezList.size()-2].second);

        DDAline(0,255,0);

    }
}

void MainWindow::on_clearbezpoint_clicked()
{
    BezList.clear();
}

void MainWindow::on_drawBezierCurve_clicked()
{
    double xu = 0.0 , yu = 0.0 , u = 0.0 ;
    int i = 0 ;
    for(u = 0.0 ; u <= 1.0 ; u += 0.0001)
    {
        xu = pow(1-u,3)*BezList[0].first+3*u*pow(1-u,2)*BezList[1].first+3*pow(u,2)*(1-u)*BezList[2].first+pow(u,3)*BezList[3].first;
        yu = pow(1-u,3)*BezList[0].second+3*u*pow(1-u,2)*BezList[1].second+3*pow(u,2)*(1-u)*BezList[2].second+pow(u,3)*BezList[3].second;
        cpoint((int)xu , (int)yu,255,0,0);
        delay(2);
    }
}





























class point2
{
    public:
    int x,y;
};

class poly2
{
    public:
        point2 p[20];
        int inter[20],x,y;
        int v,xmin,ymin,xmax,ymax;

        int c;
        void read();
        void calcs();
        void display();
        void ints(float);
        vector<int> sort(int);
};

//reading the polygon form poly to pol2
void poly2::read()
{
        int i;
        for(i=0;i<myPoly.cor.size(); i++) //ACCEPT THE VERTICES
        {

            p[i].x=myPoly.cor[i].first;
            p[i].y=myPoly.cor[i].second;

        }
        p[i].x=myPoly.cor[0].first;
        p[i].y=myPoly.cor[0].second;
        xmin=xmax=p[0].x;
        ymin=ymax=p[0].y;


}
void poly2::calcs()
{ //MAX,MIN
    for(int i=0;i<v;i++)
    {
        if(xmin>p[i].x)
        xmin=p[i].x;
        if(xmax<p[i].x)
        xmax=p[i].x;
        if(ymin>p[i].y)
        ymin=p[i].y;
        if(ymax<p[i].y)
        ymax=p[i].y;
    }
}
void poly2::display()
{
    float s,s2;

                s=ymin+0.01;
                while(s<=ymax)
                {
                    ints(s);
                    sort(s);
                    s++;
                }

}
void poly2::ints(float z) //DEFINE FUNCTION INTS
{
    int x1,x2,y1,y2,temp;
    c=0;
    for(int i=0;i<v;i++)
    {
        x1=p[i].x;
        y1=p[i].y;
        x2=p[i+1].x;
        y2=p[i+1].y;
        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
            }
            if(x<=xmax && x>=xmin)
            inter[c++]=x;
        }
    }

}

vector<int> poly2::sort(int z) //SORT FUNCTION
{
    vector<int>scan;
    int temp,j,i;


        for(i=0; i<c;i+=2)
        {
             scan.push_back(inter[i]);
             scan.push_back(z);
              scan.push_back(inter[i+1]);
               scan.push_back(z);
               return scan;
            //line(inter[i],z,inter[i+1],z);  // Used to fill the polygon ....
        }
        return scan;
}



void MainWindow::on_pushButton_clicked()
{
    myPoly.cor.clear();
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(255,255,255));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}




































void MainWindow::on_pushButton_2_clicked()
{
    r1.setX(ui->frame->x);
    r1.setY(ui->frame->y);
}




