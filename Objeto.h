#ifndef OBJETO_H
#define OBJETO_H

#include "Ponto.h"
#include "Camera.h"

class Objeto
{
public:
	Objeto(){}
	Objeto(Ponto posicao, Ponto rotacao, Ponto escala);

	void setPosition(Ponto posicao);
	void setRotation(Ponto rotacao);
	void setScale(Ponto escala);
	
	Ponto getPosition();
	Ponto getRotation();
	Ponto getScale();
	
	void move(Ponto movimento);
	void rotate(Ponto rotacao);

	void desenhar(Camera& camera);
protected:
	Ponto posicao=Ponto(0,0,0);
	Ponto rotacao=Ponto(0,0,0);
	Ponto escala=Ponto(1,1,1);
};

#endif
