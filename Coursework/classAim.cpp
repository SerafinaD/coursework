#include "classAim.hpp"

double Aim::get_X()
{
    return(Projectile::get_X());
}

double Aim::get_Y()
{
    return(Projectile::get_Y());
}

double Aim::get_velocity()
{
    return(Projectile::get_velocity());
}

double Aim::get_angle()
{
    return (angle);
}

void   Aim::set_angle(double a)
{
    angle = a;
}

void Aim::Moving(double dt)
{
    set_X(Projectile::get_X() + Projectile::get_velocity() * cos(fi) * dt);
    set_Y(Projectile::get_Y() - Projectile::get_velocity() * sin(fi) * dt);
}