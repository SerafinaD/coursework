#ifndef CALCTRD_HPP
#define CALCTRD_HPP

#include <QThread>
#include "classAim.hpp"
#include "classRocket.hpp"
#include "PaintEvent.hpp"

class Calc_Trd: public QThread
{
private:
    Aim *aim;
    Rocket *rocket;
public:
    Calc_Trd(Aim *a, Rocket *r, QObject *parent = nullptr): QThread (parent), aim(a), rocket(r)
    {
    }
    void calculate();
signals:
    void stopedThread();
};
#endif;
