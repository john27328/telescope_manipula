#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    /************************************************************************************
     *  Длина волны, нм         2325.4  1970.1  1529.6  1060.0  1014.0  852.1   706.5   *
     *  Показатель преломления 	1.489 	1.495 	1.501 	1.507 	1.507 	1.510 	1.513   *
     *  Длина волны, нм         656.3 	643.8 	632.8 	589.3 	587.6 	546.1 	486.1   *
     *  Показатель преломления 	1.514 	1.515 	1.515 	1.517 	1.517 	1.519 	1.522   *
     *  Длина волны, нм         480.0 	4358 	404.7 	365.0 	334.1 	312.6           *
     *  Показатель преломления 	1.523 	1.527 	1.530 	1.536 	1.543 	1.549           *
     ************************************************************************************/
    l1=l2=l3=0; l4=l; rF1=10; rF2=30; rF3=50;
    l1=10;
    l1HBL = new QHBoxLayout;
    l0HBL = new QHBoxLayout;
    nHBL = new QHBoxLayout;
    rF1HBL = new QHBoxLayout;
    rF2HBL = new QHBoxLayout;
    rF3HBL = new QHBoxLayout;
    lF1HBL = new QHBoxLayout;
    lF2HBL = new QHBoxLayout;
    lF3HBL = new QHBoxLayout;
    alphaHBL = new QHBoxLayout;

    l1Lbl = new QLabel("l1, mm");
    l0Lbl = new QLabel("l, mm");
    nLbl = new QLabel("n");
    rF1Lbl = new QLabel("радиус f1, mm");
    rF2Lbl = new QLabel("радиус f2, mm");
    rF3Lbl = new QLabel("радиус f3, mm");
    lF1Lbl = new QLabel("толщина линзы f1, mm");
    lF2Lbl = new QLabel("толщина линзы f2, mm");
    lF3Lbl = new QLabel("толщина линзы f3, mm");
    alphaLbl = new QLabel("половинный угол расходимости, мрад");

    l1Sb = new QDoubleSpinBox; l1Sb->setRange(0,999);
    l0Sb = new QDoubleSpinBox; l0Sb->setRange(0,999);
    nSb = new QDoubleSpinBox; nSb->setRange(1,10); nSb->setSingleStep(.001); nSb->setDecimals(3);
    rF1Sb = new QDoubleSpinBox; rF1Sb->setRange(-999,999);
    rF2Sb = new QDoubleSpinBox; rF2Sb->setRange(-999,999);
    rF3Sb = new QDoubleSpinBox; rF3Sb->setRange(-999,999);
    lF1Sb = new QDoubleSpinBox; lF1Sb->setRange(-999,999);
    lF2Sb = new QDoubleSpinBox; lF2Sb->setRange(-999,999);
    lF3Sb = new QDoubleSpinBox; lF3Sb->setRange(-999,999);
    alphaSb = new QDoubleSpinBox; alphaSb->setRange(0,3.14/2*1000);
    l0Sb->setValue(200);
    nSb->setValue(1.514);//1.46);
    rF1Sb->setValue(9.991);
    rF2Sb->setValue(20.21);
    rF3Sb->setValue(40);
    lF1Sb->setValue(3.95);
    lF2Sb->setValue(2.98);
    lF3Sb->setValue(2);
    alphaSb->setValue(220);

    //l1HBL->addWidget(l1Lbl); l1HBL->addWidget(l1Sb);
    l0HBL->addWidget(l0Lbl); l0HBL->addWidget(l0Sb);
    nHBL->addWidget(nLbl); nHBL->addWidget(nSb);
    rF1HBL->addWidget(rF1Lbl); rF1HBL->addWidget(rF1Sb);
    rF2HBL->addWidget(rF2Lbl); rF2HBL->addWidget(rF2Sb);
    rF3HBL->addWidget(rF3Lbl); rF3HBL->addWidget(rF3Sb);
    lF1HBL->addWidget(lF1Lbl); lF1HBL->addWidget(lF1Sb);
    lF2HBL->addWidget(lF2Lbl); lF2HBL->addWidget(lF2Sb);
    lF3HBL->addWidget(lF3Lbl); lF3HBL->addWidget(lF3Sb);
    alphaHBL->addWidget(alphaLbl); alphaHBL->addWidget(alphaSb);


    deltaNLbl = new QLabel("ошибка n");
    deltaNSB = new QDoubleSpinBox;
    deltaNHBL = new QHBoxLayout;
    deltaNHBL->addWidget(deltaNLbl);
    deltaNHBL->addWidget(deltaNSB);
    deltaNSB->setRange(-1,1); deltaNSB->setSingleStep(.001); deltaNSB->setDecimals(3);

    deltaL1Lbl = new QLabel("ошибка l1, мм");
    deltaL1SB = new QDoubleSpinBox;
    deltaL1HBL = new QHBoxLayout;
    deltaL1HBL->addWidget(deltaL1Lbl);
    deltaL1HBL->addWidget(deltaL1SB);
    deltaL1SB->setRange(-9,9); deltaL1SB->setSingleStep(.1);

    deltaL2Lbl = new QLabel("ошибка l2, мм");
    deltaL2SB = new QDoubleSpinBox;
    deltaL2HBL = new QHBoxLayout;
    deltaL2HBL->addWidget(deltaL2Lbl);
    deltaL2HBL->addWidget(deltaL2SB);
    deltaL2SB->setRange(-9,9); deltaL2SB->setSingleStep(.1);


    deltaRF1Lbl = new QLabel("ошибка радиуса f1, мм");
    deltaRF1SB = new QDoubleSpinBox;
    deltaRF1HBL = new QHBoxLayout;
    deltaRF1HBL->addWidget(deltaRF1Lbl);
    deltaRF1HBL->addWidget(deltaRF1SB);
    deltaRF1SB->setRange(-9,9); deltaRF1SB->setSingleStep(.1);


    deltaRF2Lbl = new QLabel("ошибка радиуса f2, мм");
    deltaRF2SB = new QDoubleSpinBox;
    deltaRF2HBL = new QHBoxLayout;
    deltaRF2HBL->addWidget(deltaRF2Lbl);
    deltaRF2HBL->addWidget(deltaRF2SB);
    deltaRF2SB->setRange(-9,9); deltaRF2SB->setSingleStep(.1);


    deltaRF3Lbl = new QLabel("ошибка радиуса f3, мм");
    deltaRF3SB = new QDoubleSpinBox;
    deltaRF3HBL = new QHBoxLayout;
    deltaRF3HBL->addWidget(deltaRF3Lbl);
    deltaRF3HBL->addWidget(deltaRF3SB);
    deltaRF3SB->setRange(-9,9); deltaRF3SB->setSingleStep(.1);



    plotGraf = new QPushButton("построить график");

    prBr = new QProgressBar;

    maneVBL = new QVBoxLayout;


    //maneVBL->addLayout(l1HBL);
    maneVBL->addLayout(l0HBL);
    maneVBL->addLayout(nHBL);
    maneVBL->addLayout(rF1HBL);
    maneVBL->addLayout(rF2HBL);
    maneVBL->addLayout(rF3HBL);
    maneVBL->addLayout(lF1HBL);
    maneVBL->addLayout(lF2HBL);
    maneVBL->addLayout(lF3HBL);
    maneVBL->addLayout(alphaHBL);

    maneVBL->addLayout(deltaNHBL);
    maneVBL->addLayout(deltaL1HBL);
    maneVBL->addLayout(deltaL2HBL);
    maneVBL->addLayout(deltaRF1HBL);
    maneVBL->addLayout(deltaRF2HBL);
    maneVBL->addLayout(deltaRF3HBL);



    //maneVBL->addWidget(plotGraf);
    //maneVBL->addWidget(prBr);





    setLayout(maneVBL);

    //alphaSb = new QDoubleSpinBox; alphaSb->setRange(0,3.14/2*1000);



    graf=new grafWidget;
    graf->nameGraf="движение линз";
    graf->nameX="увеличение";
    graf->nameY="положение линзы, мм";
    sourceL1 = new grafSource(0);
    sourceL1->pen=QPen(Qt::red,3,Qt::DotLine);
    graf->addListPoint(sourceL1);
    sourceL2 = new grafSource(0);
    sourceL2->pen=QPen(Qt::blue,3,Qt::DotLine);
    graf->addListPoint(sourceL2);
    sourceL3 = new grafSource(0);
    sourceL3->pen=QPen(Qt::green,3,Qt::DotLine);
    graf->addListPoint(sourceL3);
    sourceL4 = new grafSource(0);
    sourceL4->pen=QPen(Qt::black,3,Qt::DotLine);
    graf->addListPoint(sourceL4);
    sourceLError = new grafSource(0);
    sourceLError->pen=QPen(Qt::gray,3,Qt::DotLine);
    graf->addListPoint(sourceLError);

    grafD=new grafWidget;
    grafD->nameGraf="диаметр пучка";
    grafD->nameX="увеличение";
    grafD->nameY="диаметр пучка, мм";
    sourceF1 = new grafSource(0);
    sourceF1->pen=QPen(Qt::red,3);
    grafD->addListPoint(sourceF1);
    sourceF2 = new grafSource(0);
    sourceF2->pen=QPen(Qt::blue,3);
    grafD->addListPoint(sourceF2);
    sourceF3 = new grafSource(0);
    sourceF3->pen=QPen(Qt::green,3);
    grafD->addListPoint(sourceF3);

    grafK=new grafWidget;
    grafK->nameGraf="диаметр пучка в перетяжке";
    grafK->nameX="увеличение";
    grafK->nameY="увеличение";
    sourceK1 = new grafSource(0);
    sourceK1->pen=QPen(Qt::red,3);
    grafK->addListPoint(sourceK1);
    sourceK2 = new grafSource(0);
    sourceK2->pen=QPen(Qt::blue,3);
    grafK->addListPoint(sourceK2);

//    sourceF4 = new grafSource(0);
//    sourceF4->pen=QPen(Qt::black,3);
//    graf->addListPoint(sourceF4);

    connect(plotGraf,SIGNAL(clicked()),this,SLOT(ff()));
    connect(l0Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(rF1Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(rF2Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(rF3Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(nSb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(lF1Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(lF2Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(lF3Sb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(alphaSb,SIGNAL(valueChanged(double)),this,SLOT(ff()));

    connect(deltaRF1SB,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(deltaRF2SB,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(deltaRF3SB,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(deltaNSB,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(alphaSb,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(deltaL1SB,SIGNAL(valueChanged(double)),this,SLOT(ff()));
    connect(deltaL2SB,SIGNAL(valueChanged(double)),this,SLOT(ff()));


    ff();


}

Widget::~Widget()
{

}


QLabel *Widget::getF3Lbl() const
{
    return rF3Lbl;
}

void Widget::setF3Lbl(QLabel *value)
{
    rF3Lbl = value;
}

void Widget::ff()
{
    sourceL1->clear();
    sourceL2->clear();
    sourceL3->clear();
    sourceL4->clear();
    sourceLError->clear();

    sourceF1->clear();
    sourceF2->clear();
    sourceF3->clear();

    sourceK1->clear();
    sourceK2->clear();


    rF1=rF1Sb->value();
    rF2=rF2Sb->value();
    rF3=rF3Sb->value();

    lF1=lF1Sb->value();
    lF2=lF2Sb->value();
    lF3=lF2Sb->value();

    l4=rF3;
    l=l0Sb->value();
    alphav = alphaSb->value()/1000.;
    n = nSb->value();
    LF1=lF1+rF1-sqrt(pow(rF1,2)-pow(DF1/2.,2));
    LF2=lF2+rF2-sqrt(pow(rF2,2)-pow(DF2/2.,2));
    LF3=lF3+rF3-sqrt(pow(rF3,2)-pow(DF3/2.,2));
    //qDebug()<<LF1<<LF2<<LF3;

    //optMtr M;

    double dl2=.01;
    double k;//коэф увеличения rf/fv
    //для процесс бара
    int i=0;
    int imax=l/dl2;
    prBr->setRange(0,imax);
    //qDebug()<<l1;
    l4 = l4f();
    //qDebug()<<l4;

    for(l2=0;l2<=l;l2+=dl2)
    {
        l1 = fM1();

        l3=l-l4-l2-l1;
    //qDebug()<<l1<<l2<<l3<<l4;
        //qDebug()<<LF1<<LF2<<LF3;

        if(l1>-00 && l2>0 && l3>0 && l4>0 && (l2-LF1)>0 && (l3-LF2-LF3)>0)
//        if(l1>0 && l2>0 && l3>0 && l4>0)
        {
            //LF1=LF2=LF3=0; lF1=lF2=lF3=0;
            k=kf();//qDebug()<<k;
            if(fabs(k)<100 && fabs(k)>0){
                //qDebug()<<"!!!!!!!!!!!!!!!!!!";
                sourceF1->addPoint(k,2*rf1);
                sourceF2->addPoint(k,2*rf2);
                sourceF3->addPoint(k,2*rf3);
                sourceL1->addPoint(k,(l1));
                sourceL2->addPoint(k,(l2+l1));
                sourceL3->addPoint(k,(l3+l2+l1));
                sourceL4->addPoint(k,(l4+l2+l1+l3));
//отладка
                //qDebug()<<"*******************************";
                if(fabs(l1-9.4)<0.001)
                    qDebug()<<k<<l1<<l1+l2<<"****";
                if(fabs(l1-8.6)<0.001)
                    qDebug()<<k<<l1<<l1+l2;
                if(fabs(l1-7.6)<0.001)
                    qDebug()<<k<<l1<<l1+l2;
                if(fabs(l1-6.4)<0.001)
                    qDebug()<<k<<l1<<l1+l2;
                if(fabs(l1-5)<0.01)
                    qDebug()<<k<<l1<<l1+l2;
                if(fabs(l1-2.8)<0.01)
                    qDebug()<<k<<l1<<l1+l2;
                if(fabs(l1-0.1)<0.01)
                    qDebug()<<k<<l1<<l1+l2;

                sourceL1->addPoint(k,(l1+LF1));
                sourceL2->addPoint(k,(l2+l1+LF2));
                sourceL3->addPoint(k,(l3+l2+l1-LF3));


//                sourceL1->addPoint(k,(l1));
//                sourceL2->addPoint(k,(l2));
//                sourceL3->addPoint(k,(l3));
//                sourceL4->addPoint(k,(l4));
                errorManipula();
                sourceLError->addPoint(k,lError);
                sourceK1->addPoint(k,k);
                sourceK2->addPoint(k,k2);

            }
        }
    }
    prBr->setValue(++i);

    graf->show();
    graf->update();

    grafD->show();
    grafD->update();

    grafK->show();
    grafK->update();


    prBr->reset();
}


double Widget::fM1()
{
    /****************************************************
     *                                                  *
     *    ---\            ---\                          *
     *    |   \           |   \--------                 *
     *   /|    \          |    \         /|             *
     *  * |     )         |     )       {==========     *
     *   \|    /          |    /         \|             *
     *    |   /           |   /--------  обход          *
     *    ---/            ---/                          *
     *                                                  *
     *     MLF1 MRF1 Ml2   MLF2 MRF2                    *
     *                                                  *
     * **************************************************/
    optMtr MLF1; //толщина линзы LF1
    optMtr MRF1; //кривизна
    optMtr Ml2; //l2-LF1
    optMtr MLF2; // Lf2
    optMtr MRF2; // кривизна
    MLF1.sreda(LF1,n);
    MRF1.sferitceskayPoverhnost(rF1,1,n);
    Ml2.prostranstvo(l2-LF1);
    MLF2.sreda(LF2,n);
    MRF2.sferitceskayPoverhnost(rF2,1,n);
    optMtr M1 = MLF1 * MRF1 * Ml2 * MLF2 * MRF2;
    //qDebug()<< M1.B()<<M1.D();
    return -(M1.A()/M1.C());
}

double Widget::l4f()
{
    /********************************
     *                              *
     *        /---                  *
     *  -----/   |                  *
     *      /    |\         |\      *
     *     (     | *   =======}     *
     *      \    |/         |/      *
     *  -----\   |      обход       *
     *        \---                  *
     *                              *
     *     MRF3 MLF3                *
     *                              *
     * ******************************/
    optMtr MLF3, MRF3;
    MLF3.sreda(LF3,n);
    MRF3.sferitceskayPoverhnost(+rF3,1,n);
    optMtr MF3 = MLF3*MRF3;
    return -(MF3.A()/MF3.C());
}

double Widget::kf()
{
    /********************************************************************
     *                                                                  *
     *    ---\                ---\              /---                    *
     *    |   \               |   \------------/   |                    *
     *   /|    \              |    \          /    |\             |\    *
     *  * |     )             |     )        (     | *   ===========}   *
     *   \|    /              |    /          \    |/             |/    *
     *    |   /               |   /------------\   |         обход      *
     *    ---/                ---/              \---                    *
     *                                                                  *
     *  Ml1 MLF1 MRF1 Ml2     MLF2 MRF2 Ml3  MRF3 MLF3 ML4              *
     *                                                                  *
     * ******************************************************************/

    optMtr Ml1;
    optMtr MLF1; //толщина линзы LF1
    optMtr MRF1; //кривизна
    optMtr Ml2; //l2-LF1
    optMtr MLF2; // Lf2
    optMtr MRF2; // кривизна
    optMtr Ml3;
    optMtr MLF3;
    optMtr MRF3;
    optMtr Ml4;

    Ml1.prostranstvo(l1);
    MLF1.sreda(LF1,n);
    MRF1.sferitceskayPoverhnost(-rF1,n,1);
    Ml2.prostranstvo(l2-LF1);
    MLF2.sreda(LF2,n);
    MRF2.sferitceskayPoverhnost(-rF2,n,1);
    Ml3.prostranstvo(l3-LF2-LF3);
    MLF3.sreda(LF3,n);
    MRF3.sferitceskayPoverhnost(rF3,1,n);
    Ml4.prostranstvo(l4);

    optMtr M;


    //расчет диаметров

    M = Ml1;

    rf1=M.B()*alphav;
    //qDebug()<<rf1;
    M = Ml2*MRF1*MLF1*Ml1;
    rf2=M.B()*alphav;

    M = Ml3*MRF2*MLF2*Ml2*MRF1*MLF1*Ml1;
    rf3=M.B()*alphav;

    M = Ml4*MLF3*MRF3*Ml3*MRF2*MLF2*Ml2*MRF1*MLF1*Ml1;
return M.A();
}


void Widget::errorManipula()
{

    /********************************************************************
     *                                                                  *
     *    ---\                ---\              /---                    *
     *    |   \               |   \------------/   |                    *
     *   /|    \              |    \          /    |\             |\    *
     *  * |     )             |     )        (     | *   ===========}   *
     *   \|    /              |    /          \    |/             |/    *
     *    |   /               |   /------------\   |         обход      *
     *    ---/                ---/              \---                    *
     *                                                                  *
     *  Ml1 MLF1 MRF1 Ml2     MLF2 MRF2 Ml3  MRF3 MLF3 ML4              *
     *                                                                  *
     * ******************************************************************/
    double deltaN=deltaNSB->value();
    double deltaRF1=deltaRF1SB->value();
    double deltaRF2=deltaRF2SB->value();
    double deltaRF3=deltaRF3SB->value();
    double deltaL1=deltaL1SB->value();
    double deltaL2=deltaL2SB->value();

    optMtr Ml1;
    optMtr MLF1; //толщина линзы LF1
    optMtr MRF1; //кривизна
    optMtr Ml2; //l2-LF1
    optMtr MLF2; // Lf2
    optMtr MRF2; // кривизна
    optMtr Ml3;
    optMtr MLF3;
    optMtr MRF3;
    optMtr Ml4;

    Ml1.prostranstvo(l1+deltaL1);
    MLF1.sreda(LF1,n+deltaN);
    MRF1.sferitceskayPoverhnost(-rF1-deltaRF1,n+deltaN,1);
    Ml2.prostranstvo(l2-LF1+deltaL2);
    MLF2.sreda(LF2,n+deltaN);
    MRF2.sferitceskayPoverhnost(-rF2-deltaRF2,n+deltaN,1);
    Ml3.prostranstvo(l3-LF2-LF3);
    MLF3.sreda(LF3,n+deltaN);
    MRF3.sferitceskayPoverhnost(rF3+deltaRF3,1,n+deltaN);
    Ml4.prostranstvo(l4);

    optMtr M;



    M = Ml4*MLF3*MRF3*Ml3*MRF2*MLF2*Ml2*MRF1*MLF1*Ml1;



    double l4Error = -(M.B()/M.D());
    lError = l1 + deltaL1 + l2 + deltaL2 + l3 + l4 + l4Error;
    Ml4.prostranstvo(l4+l4Error);

    M = Ml4*MLF3*MRF3*Ml3*MRF2*MLF2*Ml2*MRF1*MLF1*Ml1;
    k2=M.A();
    //qDebug()<<lError<<l1Error<<l2Error<<l3<<l4Error;
}

