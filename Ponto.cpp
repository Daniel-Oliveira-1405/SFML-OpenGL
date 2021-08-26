#include "Ponto.h"
#include<cmath>

Ponto::Ponto(float x, float y, float z)
: x(x), y(y), z(z) {
	
}

Ponto::Ponto(const Ponto& p)
: x(p.x), y(p.y), z(p.z) {
}

Ponto::Ponto(float p[3])
: x(p[0]), y(p[1]), z(p[2])
{
	
}

void Ponto::operator=(Ponto p)
{
	x=p.x; y=p.y; z=p.z;
}

void Ponto::operator=(float p[3])
{
	x=p[0]; y=p[1]; z=p[2];
}

Ponto Ponto::operator+(Ponto p)
{
	return Ponto(x+p.x, y+p.y, z+p.z);
}

Ponto Ponto::operator-(Ponto p)
{
	return Ponto(x-p.x, y-p.y, z-p.z);
}

Ponto Ponto::operator*(Ponto p)
{
	return Ponto(x*p.x, y*p.y, z*p.z);
}

void Ponto::operator+=(Ponto p)
{
	x+=p.x; y+=p.y; z+=p.z;
}

void Ponto::operator-=(Ponto p)
{
	x-=p.x; y-=p.y; z-=p.z;
}

void Ponto::operator*=(Ponto p)
{
	x-=p.x; y-=p.y; z*=p.z;
}

Ponto Ponto::operator*(float p)
{
	return Ponto(x*p, y*p, z*p);
}

void Ponto::operator*=(float p)
{
	x*=p; y*=p; z*=p;
}

Ponto Ponto::normal()
{
	float w = sqrt(x*x + y*y + z*z);
	return Ponto(x/w, y/w, z/w);
}

void Ponto::normalize()
{
	*this = normal();
}
