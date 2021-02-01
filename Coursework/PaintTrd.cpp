#include <QApplication>
#include "PaintEvent.hpp"
#include "PaintTrd.hpp"

Paint_Trd::Paint_Trd(QObject *obj): QThread(obj), isWork(true)
{
}

void Paint_Trd::run()
{
    while (isWork)
    {}
}

void Paint_Trd::paint(int xt, int yt, int xr, int yr)
{
    PaintEvent *p_ev = new PaintEvent();
    p_ev->setPoints(xt, yt, xr, yr);
    QApplication::postEvent(parent(), p_ev);
}

void Paint_Trd::boom()
{
    PaintEvent *p_ev = new PaintEvent();
    p_ev->setPoints(0,0,0,0);
    QApplication::postEvent(parent(), p_ev);
    isWork = false;
}
