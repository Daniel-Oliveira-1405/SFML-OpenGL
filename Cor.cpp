#include "Cor.h"

Cor::Cor(unsigned char c[4])
{
	r = c[0];
	g = c[1];
	b = c[2];
	a = c[3];
}

Cor::Cor(int num)
{
	union C
	{
		int n;
		char c[4];
	};
	C j;
	
	j.n = num;
	
	r = (float)j.c[0]/255.0f;
	g = (float)j.c[1]/255.0f;
	b = (float)j.c[2]/255.0f;
	a = (float)j.c[3]/255.0f;
}

void Cor::operator+=(Cor c)
{
	r+=c.r;
	g+=c.g;
	b+=c.b;
	a+=c.a;

	if(r>1) r=1;
	if(g>1) g=1;
	if(b>1) b=1;
	if(a>1) a=1;
}

void Cor::operator-=(Cor c)
{
	r-=c.r;
	g-=c.g;
	b-=c.b;
	a-=c.a;

	if(r<0) r=0;
	if(g<0) g=0;
	if(b<0) b=0;
	if(a<0) a=0;
}

Cor Cor::operator+(Cor c)
{
	Cor d = *this;
	d+=c;

	return d;
}

Cor Cor::operator-(Cor c)
{
	Cor d = *this;
	d-=c;
	
	return d;
}
