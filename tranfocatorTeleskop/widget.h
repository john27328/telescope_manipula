#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "optmtr.h"
#include <QDebug>
#include "grafsource.h"
#include "grafwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    grafSource *sF0;
    grafSource *sF1;
    grafSource *sF2;
    grafSource *sF3;
    grafSource *sF4;

    grafSource *diametr1;
    grafSource *diametr2;
    grafSource *diametr3;
    grafSource *diametr4;
    grafSource *diametr5;
    grafSource *diametr6;
    grafSource *diametr7;
    grafSource *diametr8;



    grafWidget *diametrGraf;
    double f1;
    double f2;
    double f3;
    double l;
    //qDebug()<<lf2;

    optMtr F1;
    optMtr F2;
    optMtr F3;
    optMtr L2;

    //поиск f23

    optMtr F23;
    double f23;
    double l1;
    double l2;
    optMtr L1;
    optMtr F1F2F3;
    optMtr LF0;
    double f0;
    optMtr F0;
    double l0;
    optMtr L0;
    double l3;
    optMtr L3;
    double f4;
    optMtr F4;
    double lMan;
    optMtr L4;
    double alpha;
    double l2max;
    double kT1;
    double kT2;

private:
    Ui::Widget *ui;
private slots:
    void MF1F2F3();
    void start();
    void k();
    void plot();
    void l2maxf();
    void l2slider();
    void setl2Slider();

};

#endif // WIDGET_H
