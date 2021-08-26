#ifndef CUBO_H
#define CUBO_H

#include "Objeto.h"
#include "Cor.h"

#define FRONT 0
#define BACK  1
#define RIGHT 2
#define LEFT  3
#define UP    4
#define DOWN  5

class Cubo : public Objeto
{
public:
	Cubo(Ponto posicao, float tamanho);
	Cubo(Cubo& cubo);
	Cubo()
	{
		this->posicao = Ponto(0,0,0);
		this->escala = Ponto(1, 1, 1);
	}
	
	void operator=(Cubo& cubo);
	
	void setFaceColor(int face, Cor c);
	Cor getFaceColor(int face);
	
	void setFaceTexture(int face, int texture);
	int getFaceTexture(int face);
	
	void desenhar(Camera& camera);
protected:
	Cor cores[6];
	int texturas[6];
};

#endif
