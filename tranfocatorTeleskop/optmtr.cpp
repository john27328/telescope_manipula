#include "optmtr.h"
#include <qstring.h>

optMtr::optMtr()
{
    //ploskoeZerkalo();
}

optMtr::optMtr(QString Name)
{
    name=Name;
}

void optMtr::Name(QString Name)
{
    name=Name;
}

QString optMtr::Name()
{
    return name;
}

void optMtr::printName()
{
    //qDebug() << name;
}

void optMtr::ploskoeZerkalo()
{
    A(1); B(0);
    C(0); D(1);
}


void optMtr::sferitceskoeZerkalo(double r)
{
    A(1); B(0);
    C(-2/r); D(1);
}

void optMtr::prostranstvo(double d)
{
    A(1); B(d);
    C(0); D(1);
}

void optMtr::linza(double f)
{
    A(1); B(0);
    C(-1/f); D(1);
}

void optMtr::sreda(double d, double n)
{
    A(1); B(d/n);
    C(0); D(1);
}

void optMtr::sferitceskayPoverhnost(double r, double n1, double n2)
{
    A(1);           B(0);
    C(-(n2-n1)/r);  D(1);
}

double optMtr::A()
{
    return mas[0][0];
}

double optMtr::B()
{
    return mas[0][1];
}

double optMtr::C()
{
    return mas[1][0];
}

double optMtr::D()
{
    return mas[1][1];
}

void optMtr::A(double a)
{
    mas[0][0]=a;
}

void optMtr::B(double a)
{
    mas[0][1]=a;
}

void optMtr::C(double a)
{
    mas[1][0]=a;
}

void optMtr::D(double a)
{
    mas[1][1]=a;
}

optMtr optMtr::operator +(const optMtr m2)
{
    optMtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            m3.mas[i][j]=mas[i][j]+m2.mas[i][j];

    return m3;
}

optMtr optMtr::operator *(const optMtr m2)
{
    optMtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            for(int r=0;r<nm;r++)
                m3.mas[i][j]+=mas[i][r]*m2.mas[r][j];

    return m3;
}

optMtr optMtr::operator =(const optMtr m2)
{
    optMtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            mas[i][j]=m2.mas[i][j];

    return m3;
}
