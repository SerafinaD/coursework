#ifndef AIM
#define AIM 

#include "classProjectile.hpp"

class Aim: public Projectile
{
    private:
    double angle;
    public:
    Aim(double fi, double x, double y, double v):
        angle(fi), Projectile(x, y, v)
    {
    }
    double  get_angle();
    double  get_X();
    double  get_Y();
    double  get_velocity();
    void    set_angle(double a);
    void Moving(double dt);
};

#endif