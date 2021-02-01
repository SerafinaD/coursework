#ifndef PROJECTILE
#define PROJECTILE
#include <cmath>

class Projectile
{
    private:
        double coord_x, coord_y;
        double velocity;
    public:
        Projectile(double x, double y, double v):
            coord_x(x), coord_y(y), velocity(v)
        {
        }
        double  get_X() const;
        double  get_Y() const;
        double  get_velocity() const;
        void  set_X(double x);
        void  set_Y(double y);
        void  set_velocity(double v);
        virtual void    Moving(double dt) = 0;
        virtual ~Projectile();
};

#endif
