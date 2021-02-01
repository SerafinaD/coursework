#ifndef CALCTRD_HPP
#define CALCTRD_HPP

#include <QObject>
#include <QThread>
#include "classAim.hpp"
#include "classRocket.hpp"

class Calc_Trd: public QThread
{
    Q_OBJECT
private:
    Aim     *aim;
    Rocket  *rocket;
    double  time;
    bool    isWork;
public:
    Calc_Trd(Aim *a, Rocket *r, double t, QObject *parent = nullptr): QThread (parent), aim(a), rocket(r), time(t)
    {
        isWork = true;
    }
    void calcStop()
    {
        isWork = false;
    }

protected:
    void run();
signals:
   void paintThread(int xt, int yt, int xr, int yr);
   void stopedThread();

};

#endif
