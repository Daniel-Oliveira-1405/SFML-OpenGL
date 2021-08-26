#ifndef CAMERA_H
#define CAMERA_H

#include "Ponto.h"

class Camera
{
public:
	enum EIXO
	{
		X=0, Y, Z
	};
	
	Camera() : posicao(0, 0, 0), rotacao(0, 0, 0), campoDeVisao(60) {}
	
	Camera(Ponto posicao, Ponto rotacao, float campoDeVisao)
	: posicao(posicao), rotacao(rotacao),campoDeVisao(campoDeVisao) {}
	
	void setPosition(Ponto posicao);
	void setPosition(float x, float y, float z);
	Ponto getPosition();
	
	void setRotation(Ponto rotacao);
	void setRotation(float x, float y, float z);
	Ponto getRotation();
	
	void setCampoDeVisao(float angulo);
	float getCampoDeVisao();
	
	void move(Ponto movimento);
	void move(float x, float y, float z);
	void move(Camera::EIXO eixo, float distancia);
	
	void rotate(Ponto rotacao);
	void rotate(float x, float y, float z);
protected:
	Ponto posicao;
	Ponto rotacao;
	float campoDeVisao;
};

#endif
