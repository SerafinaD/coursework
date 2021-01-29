#ifndef AIM
#define AIM 

#include "classProjectile.hpp"

class Aim: public Projectile
{
    private:
    double angle;
    public:
    Aim(double x, double y, double v, double fi):
         Projectile(x, y, v), angle(fi)
    {
    }
    double  get_angle() const;
    double  get_X() const;
    double  get_Y() const;
    double  get_velocity() const;
    void    set_angle(double a);
    void Moving(double dt);
};

#endif
