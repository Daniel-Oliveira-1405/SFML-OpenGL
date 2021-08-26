#ifndef COR_H
#define COR_H

class Cor
{
public:
	Cor() : r(0), g(0), b(0), a(1) {}
	Cor(float r, float g, float b, float a=1)
	: r(r), g(g), b(b), a(a) {}
	
	Cor(float c[4]) : r(c[0]), g(c[1]), b(c[2]), a(c[3]) {}
	
	Cor(unsigned char c[4]);
	Cor(int num);

	void operator+=(Cor c);
	void operator-=(Cor c);
	
	Cor operator+(Cor c);
	Cor operator-(Cor c);
	
	float r, g, b, a;
};

#endif
