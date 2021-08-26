#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "Ponto.h"

class Segmento
{
public:
	Segmento() : a(), b() {}
	Segmento(Ponto a, Ponto b);
	Segmento(const Segmento& s);
	Segmento(float s[2][3]);

	void operator=(Segmento s);
	void operator=(Ponto p[2]);
	void operator=(float p[2][3]);

	Segmento operator+(Ponto p);
	Segmento operator-(Ponto p);
	
	void operator+=(Ponto p);
	void operator-=(Ponto p);

	Ponto a, b;
};

#endif
