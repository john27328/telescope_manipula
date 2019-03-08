#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "grafwidget.h"
#include "grafsource.h"
#include "optmtr.h"



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    grafWidget *graf;
    grafSource *sourceL1;
    grafSource *sourceL2;
    grafSource *sourceL3;
    grafSource *sourceL4;
    grafSource *sourceLError;

    grafWidget *grafD;
    grafSource *sourceF1;
    grafSource *sourceF2;
    grafSource *sourceF3;
    grafSource *sourceF4;

    grafWidget *grafK;
    grafSource *sourceK1;
    grafSource *sourceK2;

    double l1,l2,l3,l4,l, lError;
    double rF1, rF2, rF3; //радиус кривизны линзы
    double rv,rf, rf3, rf2, rf1; //радиус пучка на линзе
    double lF1,lF2,lF3; //толщина кромки линзы
    double LF1,LF2,LF3; //толщина линз
    double alphav;
    double n;
    double DF1 = 0;// 25.4;
    double DF2 = 0;//25.4;
    double DF3 = 0;//25.4;
    double k2;
//    double DF1 = 25.4;
//    double DF2 = 25.4;
//    double DF3 = 25.4;

    QLabel *l1Lbl;
    QLabel *l0Lbl;
    QLabel *nLbl;
    QLabel *rF1Lbl;
    QLabel *rF2Lbl;
    QLabel *rF3Lbl;
    QLabel *lF1Lbl;
    QLabel *lF2Lbl;
    QLabel *lF3Lbl;
    QLabel *alphaLbl;

    QDoubleSpinBox *l1Sb;
    QDoubleSpinBox *l0Sb;
    QDoubleSpinBox *nSb;
    QDoubleSpinBox *rF1Sb;
    QDoubleSpinBox *rF2Sb;
    QDoubleSpinBox *rF3Sb;
    QDoubleSpinBox *lF1Sb;
    QDoubleSpinBox *lF2Sb;
    QDoubleSpinBox *lF3Sb;
    QDoubleSpinBox *alphaSb;

    QHBoxLayout *l1HBL;
    QHBoxLayout *l0HBL;
    QHBoxLayout *nHBL;
    QHBoxLayout *rF1HBL;
    QHBoxLayout *rF2HBL;
    QHBoxLayout *rF3HBL;
    QHBoxLayout *lF1HBL;
    QHBoxLayout *lF2HBL;
    QHBoxLayout *lF3HBL;
    QHBoxLayout *alphaHBL;

    QVBoxLayout *maneVBL;

    QPushButton *plotGraf;

    QProgressBar *prBr;

    QLabel *deltaNLbl;
    QDoubleSpinBox *deltaNSB;
    QHBoxLayout *deltaNHBL;

    QLabel *deltaL1Lbl;
    QDoubleSpinBox *deltaL1SB;
    QHBoxLayout *deltaL1HBL;

    QLabel *deltaL2Lbl;
    QDoubleSpinBox *deltaL2SB;
    QHBoxLayout *deltaL2HBL;

    QLabel *deltaRF1Lbl;
    QDoubleSpinBox *deltaRF1SB;
    QHBoxLayout *deltaRF1HBL;

    QLabel *deltaRF2Lbl;
    QDoubleSpinBox *deltaRF2SB;
    QHBoxLayout *deltaRF2HBL;

    QLabel *deltaRF3Lbl;
    QDoubleSpinBox *deltaRF3SB;
    QHBoxLayout *deltaRF3HBL;


    double kf();
    double fM1();
    double l4f();

    void errorManipula();

    QLabel *getF3Lbl() const;
    void setF3Lbl(QLabel *value);

private slots:
    void ff();
};

#endif // WIDGET_H
