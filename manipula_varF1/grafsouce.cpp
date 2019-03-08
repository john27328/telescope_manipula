#include "grafsource.h"
#include <QDebug>
grafSource::grafSource(int nList)
{
    n=nList;
    iList=0;

}

grafSource::grafSource()
{

}

void grafSource::addPoint(QPointF point)
{
    iList++;
    if(n>0 && iList>n)
        xyList.removeFirst();
    xyList<<point;
}

void grafSource::addPoint(double x,double y)
{
    addPoint(QPointF(x,y));
}

void grafSource::addPointLists(QList<double> xList, QList<double> yList)
{
    int n = xList.size();
    int m = yList.size();
    if (m>n) n=m;
    for (int i=0;i<n;i++)
    {
        addPoint(xList[i],yList[i]);
    }
}

void grafSource::clear()
{
    iList = 0;
    xyList.clear();
}
