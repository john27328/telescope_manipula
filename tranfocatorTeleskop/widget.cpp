#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //qDebug()<<lf();

    diametr1 = new grafSource(0);
    diametr2 = new grafSource(0);
    diametr3 = new grafSource(0);
    diametr4 = new grafSource(0);
    diametr5 = new grafSource(0);
    diametr6 = new grafSource(0);
    diametr7 = new grafSource(0);
    diametr8 = new grafSource(0);


    diametrGraf = new grafWidget;
    diametrGraf->addListPoint(diametr1);
    diametrGraf->addListPoint(diametr2);
    diametrGraf->addListPoint(diametr3);
    diametrGraf->addListPoint(diametr4);
    diametrGraf->addListPoint(diametr5);
    diametrGraf->addListPoint(diametr6);
    diametrGraf->addListPoint(diametr7);
    diametrGraf->addListPoint(diametr8);

    diametrGraf->nameGraf="радиус пучка";
    diametrGraf->nameX="L";
    diametrGraf->nameY="радиус пучка, мм";
    diametr1->pen=QPen(Qt::red,3);
    diametr2->pen=QPen(Qt::red,3);
    diametr3->pen=QPen(Qt::green,3);
    diametr4->pen=QPen(Qt::green,3);
    diametr5->pen=QPen(Qt::darkRed,3);
    diametr6->pen=QPen(Qt::darkRed,3);
    diametr7->pen=QPen(Qt::darkGreen,3);
    diametr8->pen=QPen(Qt::darkGreen,3);
    diametrGraf->show();

    sF0 = new grafSource(0);
    sF0->pen=QPen(Qt::blue,3);
    diametrGraf->addListPoint(sF0);

    sF1 = new grafSource(0);
    sF1->pen=QPen(Qt::blue,3);
    diametrGraf->addListPoint(sF1);

    sF2 = new grafSource(0);
    sF2->pen=QPen(Qt::blue,3);
    diametrGraf->addListPoint(sF2);

    sF3 = new grafSource(0);
    sF3->pen=QPen(Qt::blue,3);
    diametrGraf->addListPoint(sF3);

    sF4 = new grafSource(0);
    sF4->pen=QPen(Qt::blue,3);
    diametrGraf->addListPoint(sF4);

    connect(ui->doubleSpinBoxF1,SIGNAL(valueChanged(double)),this,SLOT(start()));
    connect(ui->doubleSpinBoxF2,SIGNAL(valueChanged(double)),this,SLOT(start()));
    connect(ui->doubleSpinBoxF3,SIGNAL(valueChanged(double)),this,SLOT(start()));
    connect(ui->doubleSpinBoxL,SIGNAL(valueChanged(double)),this,SLOT(start()));
    connect(ui->doubleSpinBoxL2,SIGNAL(valueChanged(double)),this,SLOT(start()));
    connect(ui->horizontalSliderL2,SIGNAL(valueChanged(int)),this,SLOT(l2slider()));
    connect(ui->doubleSpinBoxL2,SIGNAL(valueChanged(double)),this,SLOT(setl2Slider()));
    start();
}

Widget::~ Widget()
{
    delete ui;
}

void Widget::MF1F2F3()
{
    f1 = ui->doubleSpinBoxF1->value();
    f2 = ui->doubleSpinBoxF2->value();
    f3 = ui->doubleSpinBoxF3->value();
    l = ui->doubleSpinBoxL->value();
    l2 = ui->doubleSpinBoxL2->value();

    //qDebug()<<lf2;

    F1.linza(f1);
    F2.linza(f2);
    F3.linza(f3);
    L2.prostranstvo(l2);

    //поиск f23

    F23 = F2 * L2 * F3;
    f23 = - F23.A()/F23.C();
    l1 = f1+f23;
    if (l1<0 || l2>l2max) l1=0;
    ui->lcdNumberL1->display(l1);
    L1.prostranstvo(l1);
    F1F2F3 = F3*L2*F2*L1*F1;
    ui->lcdNumberKTr->display(F1F2F3.A());
}

void Widget::start()
{
    //рассчет l1
    MF1F2F3();
    //рассчет K=A
    k();
    plot();
}

void Widget::k()
{
    optMtr M; M.ploskoeZerkalo();
    f0 = ui->doubleSpinBoxFKoll->value();
    LF0.prostranstvo(f0);
    F0.linza(f0);
    lMan = ui->doubleSpinBoxL->value();
    f4 = ui->doubleSpinBoxFFoc->value();
    l3 = ui->doubleSpinBoxL3->value();
    l0 = lMan - f4 - l3 - l2 - l1 -f0;
    ui->lcdNumberL0->display(l0);
    //qDebug()<<"l1"<<l1<<"L2"<<l2;
    L0.prostranstvo(l0);
    L3.prostranstvo(l3);
    F4.linza(f4);
    L4.prostranstvo(f4);
    M=L4*F4*L3*F3*L2*F2*L1*F1*L0*F0*LF0;
    ui->lcdNumberK->display(M.A());

}

void Widget::plot()
{
    l2maxf();
    ui->doubleSpinBoxL2->setRange(0,l2max+100);
    double dF=15;
    sF0->clear();
    sF1->clear();
    sF2->clear();
    sF3->clear();
    sF4->clear();

    diametr1->clear();
    diametr1->addPoint(0,0);
    diametr2->clear();
    diametr2->addPoint(0,0);
    diametr3->clear();
    diametr3->addPoint(0,.5);
    diametr4->clear();
    diametr4->addPoint(0,-.5);
    diametr5->clear();
    diametr5->addPoint(0,.5);
    diametr6->clear();
    diametr6->addPoint(0,-.5);
    diametr7->clear();
    diametr7->addPoint(0,.5);
    diametr8->clear();
    diametr8->addPoint(0,-.5);


    optMtr M; M.ploskoeZerkalo();
    double L=0;
    double alpha = ui->doubleSpinBoxAlpha->value();

    M=LF0*M;
    L+=f0;
    double deltaLKol = ui->doubleSpinBoxDeltaLKol->value();
    optMtr DeltaLKol; DeltaLKol.prostranstvo(deltaLKol);
    L+=deltaLKol;
    M=DeltaLKol*M;
    sF0->addPoint(L,dF/2);
    sF0->addPoint(L,-dF/2);

    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));

    double deltaL1 = ui->doubleSpinBoxDeltaL1->value();
    optMtr DeltaL1; DeltaL1.prostranstvo(deltaL1);
    M=L0*F0*M;
    L+=l0-deltaL1;
    sF1->addPoint(L,dF/2);
    sF1->addPoint(L,-dF/2);
    if (l1<0)     sF1->pen=QPen(Qt::red,3);
    else     sF1->pen=QPen(Qt::blue,3);
    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));


    M=L1*F1*M;
    L+=l1;

    L+=deltaL1;
    M=DeltaL1*M;
    sF2->addPoint(L,dF/2);
    sF2->addPoint(L,-dF/2);
    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));


    M=L2*F2*M;
    L+=l2;
    sF3->addPoint(L,dF/2);
    sF3->addPoint(L,-dF/2);
    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));


    M=L3*F3*M;
    L+=l3;
    sF4->addPoint(L,dF/2);
    sF4->addPoint(L,-dF/2);
    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));

    double deltaL4;

    M=L4*F4*M;
    L+=f4;
    deltaL4 = -M.B()/M.D();
    L+=deltaL4;
    ui->lcdNumberDeltaLFoc->display((int(deltaL4*100))/100.);
    //ui->lcdNumberDeltaLFoc->display(-1.48e-15);
    optMtr DeltaL4; DeltaL4.prostranstvo(deltaL4);
    M=DeltaL4*M;
    diametr1->addPoint(L,M.B()*alpha);
    diametr2->addPoint(L,-M.B()*alpha);
    diametr3->addPoint(L,M.A()*0.5);
    diametr4->addPoint(L,-M.A()*0.5);
    diametr5->addPoint(L,M.A()*0.5+M.B()*alpha);
    diametr6->addPoint(L,-(M.A()*0.5+M.B()*alpha));
    diametr7->addPoint(L,M.A()*0.5-M.B()*alpha);
    diametr8->addPoint(L,-(M.A()*0.5-M.B()*alpha));

    //qDebug()<<"delta L1"<<deltaL1<<"delta LKol"<<deltaLKol<<"delta LFok"<<deltaL4;
    ui->lcdNumberK1->display(f4/f0/kT1);
    ui->lcdNumberK2->display(f4/f0/kT2);

    diametrGraf->update();
}

void Widget::l2maxf()
{
    double f1 = ui->doubleSpinBoxF1->value();
    double f2 = ui->doubleSpinBoxF2->value();
    double f3 = ui->doubleSpinBoxF3->value();
    double f12 = f1*f2/(f1+f2);
    double f23 = f2*f3/(f2+f3);
    l2max = f12 + f3;
    qDebug()<<"kT1"<<(kT1 = f23/f1);
    qDebug()<<"kT2"<<(kT2 = f3/f12);
}

void Widget::l2slider()
{
    ui->doubleSpinBoxL2->setValue(ui->horizontalSliderL2->value()/100000.*l2max);
}

void Widget::setl2Slider()
{
    ui->horizontalSliderL2->setValue(ui->doubleSpinBoxL2->value()/l2max*100000);
}

