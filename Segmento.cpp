#include "Segmento.h"

Segmento::Segmento(Ponto a, Ponto b)
: a(a), b(b)
{	
}

Segmento::Segmento(const Segmento& s)
: a(s.a), b(s.b)
{
}

Segmento::Segmento(float s[2][3])
: a(s[0]), b(s[1])
{
}

void Segmento::operator=(Segmento s)
{
	a = s.a;
	b = s.b;
}

void Segmento::operator=(Ponto p[2])
{
	a = p[0];
	b = p[1];
}

void Segmento::operator=(float p[2][3])
{
	a = p[0];
	b = p[1];
}

void Segmento::operator+=(Ponto p)
{
	a+=p; b+=p;
}

void Segmento::operator-=(Ponto p)
{
	a-=p; b-=p;
}

Segmento Segmento::operator+(Ponto p)
{
	return Segmento(a+p, b+p);
}

Segmento Segmento::operator-(Ponto p)
{
	return Segmento(a-p, b-p);
}
