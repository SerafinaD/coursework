#ifndef PAINTTRD_HPP
#define PAINTTRD_HPP

#include <QThread>


class Paint_Trd: public QThread
{
private:
    Aim *aim;
    Rocket *rocket;
public:
    Calc_Trd(Aim *a, Rocket *r, QObject *parent = nullptr): QThread (parent), aim(a), rocket(r)
    {
    }
    
signals:
   void stopedThread();
};
#endif;
