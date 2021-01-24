#include "classProjectile.hpp"

double Projectile::get_X()
{
    return (coord_x);
}

double Projectile::get_Y()
{
    return (coord_y);
}

double  Projectile::get_velocity()
{
    return (velocity);
}

void Projectile::set_X(double x)
{
    coord_x = x;
}

void Projectile::set_Y(double y)
{
    coord_y = y;
}

void  Projectile::set_velocity(double v)
{
    velocity = v;
}