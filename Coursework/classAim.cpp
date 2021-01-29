#include "classAim.hpp"

double Aim::get_X() const
{
    return(Projectile::get_X());
}

double Aim::get_Y() const
{
    return(Projectile::get_Y());
}

double Aim::get_velocity() const
{
    return(Projectile::get_velocity());
}

double Aim::get_angle() const
{
    return (angle);
}

void   Aim::set_angle(double a)
{
    angle = a;
}

void Aim::Moving(double dt)
{
    set_X(Projectile::get_X() + Projectile::get_velocity() * cos(angle) * dt);
    set_Y(Projectile::get_Y() - Projectile::get_velocity() * sin(angle) * dt);
}
