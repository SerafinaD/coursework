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
    Rocket(double x, double y, double v, Aim *a):
       Projectile(x, y, v), time(0.0),  aim(a)
    {
    }
    double  get_X() const;
    double  get_Y() const;
    double  get_velocity() const;
    void    Moving(double dt);
    ~Rocket();
};

#endif
