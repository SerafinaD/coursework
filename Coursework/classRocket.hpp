#ifndef ROCKET
#define ROCKET

#include "classProjectile.hpp"
#include "classAim.hpp"

class Rocket: public Projectile
{
    private:
    double time;
    Aim *aim;
    double Runge_Kutta(double coord, double dt, char c_type);
    double calcR_K(double coord, double dt, char c_type);
    public:
    Rocket(Aim *a, double t, double x, double y, double v):
        aim(a), time(t), Projectile(x, y, v)
    {
    }
    double  get_X();
    double  get_Y();
    void    set_Time(double t);
    void    Moving(double dt);
};

#endif