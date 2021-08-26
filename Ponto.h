#ifndef PONTO_H
#define PONTO_H

class Ponto
{
public:
	Ponto() : x(0), y(0), z(0) {}
	Ponto(float x, float y, float z);
	Ponto(const Ponto& p);
	Ponto(float p[3]);

	void operator=(Ponto p);
	void operator=(float p[3]);
	
	Ponto operator+(Ponto p);
	Ponto operator-(Ponto p);
	Ponto operator*(Ponto p);
	
	Ponto operator*(float p);

	void operator+=(Ponto p);
	void operator-=(Ponto p);
	void operator*=(Ponto p);

	void operator*=(float p);
	
	Ponto normal();
	void normalize();
	
	float x, y, z;
};

#endif
