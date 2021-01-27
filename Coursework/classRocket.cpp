#include "classRocket.hpp"

double Rocket::get_X()
{
    return(Projectile::get_X());
}

double Rocket::get_Y()
{
    return(Projectile::get_Y());
}

double Rocket::calcR_K(double coord, double t, char c_type)
{
    double x_aim_velo = aim->get_velocity() * cos(aim->get_angle());
    double y_aim_velo = aim->get_velocity() * sin(aim->get_angle());
    double ans;
    if (c_type == 'x')
    {
        ans = Projectile::get_velocity() * (x_aim_velo * t + aim->get_X() - coord) /
		sqrt((x_aim_velo * t + aim->get_X() - get_X()) *
        (x_aim_velo * t + aim->get_X() - get_X()) +
        (-y_aim_velo * t + aim->get_Y() - get_Y()) *
        (-y_aim_velo * t + aim->get_Y() - get_Y()));
    }
    else
        ans = Projectile::get_velocity() * (-y_aim_velo * t + aim->get_Y() - coord) /
        sqrt((x_aim_velo * t + aim->get_X() - get_X()) *
        (x_aim_velo * t + aim->get_X() - get_X()) +
        (-y_aim_velo * t + aim->get_Y() - get_Y()) *
        (-y_aim_velo * t + aim->get_Y() - get_Y()));
}

double Rocket::Runge_Kutta(double coord, double dt, char c_type)
{
    double c0;
	double c1;
	double c2;
	double c3;
	c0 = calcR_K(coord, time, c_type) * dt;
	c1 = calcR_K(coord + c0 / 2, time + dt / 2, c_type) * dt;
	c2 = calcR_K(coord + c1 / 2, time + dt / 2, c_type) * dt;
	c3 = calcR_K(coord + c2, time + dt, c_type) * dt;
	return (coord + (c0 + 2 * c1 + 2 * c2 + c3) / 6);
}

void Rocket::Moving(double dt)
{
    set_X(Runge_Kutta(Projectile::get_X(), dt, 'x'));
    set_Y(Runge_Kutta(Projectile::get_Y(), dt, 'y'));
    time += dt;
}