#include "CalcTrd.hpp"
#include <QApplication>

void Calc_Trd::run()
{
    double t = 0;
    double dt = 0.0001;
    double iter = 0;
    while(((abs(static_cast<int>(aim->get_X() - rocket->get_X())) > 4) || (abs(static_cast<int>(aim->get_Y() - rocket->get_Y())) > 4)) && isWork)
    {
        while (t < time && isWork)
        {
            iter += dt;
            t += dt;
            aim->Moving(dt);
            if(aim->get_velocity() * iter >= 1)
            {
                emit paintThread(static_cast<int>(aim->get_X()), static_cast<int>(aim->get_Y()), static_cast<int>(rocket->get_X()), static_cast<int>(rocket->get_Y()));
                iter = 0;
            }
        }
        if (!isWork)
            break;
        iter += dt;
        t += dt;
        aim->Moving(dt);
        rocket->Moving(dt);
        if((((aim->get_velocity() > rocket->get_velocity()) ? rocket->get_velocity() : aim->get_velocity()) * iter) >= 1)
        {
            emit paintThread(static_cast<int>(aim->get_X()), static_cast<int>(aim->get_Y()), static_cast<int>(rocket->get_X()), static_cast<int>(rocket->get_Y()));
            iter = 0;
        }
    }
    emit stopedThread();
}
