#include "Camera.h"
#include<cmath>

using namespace std;

void Camera::setPosition(Ponto posicao)
{
	this->posicao = posicao;
}

void Camera::setPosition(float x, float y, float z)
{
	this->posicao = Ponto(x, y, z);
}

Ponto Camera::getPosition()
{
	return this->posicao;
}

void Camera::setRotation(Ponto rotacao)
{
	if(rotacao.x>90) rotacao.x=90;
	if(rotacao.x<-90) rotacao.x=-90;
	
	this->rotacao = rotacao;
}

void Camera::setRotation(float x, float y, float z)
{
	if(rotacao.x>90) rotacao.x=90;
	if(rotacao.x<-90) rotacao.x=-90;

	this->rotacao = Ponto(x, y, z);
}

Ponto Camera::getRotation()
{
	return this->rotacao;
}

void Camera::setCampoDeVisao(float angulo)
{
	this->campoDeVisao = angulo;
}

float Camera::getCampoDeVisao()
{
	return this->campoDeVisao;
}

void Camera::move(Ponto movimento)
{
	this->posicao+=movimento;
}

void Camera::move(float x, float y, float z)
{
	this->posicao+=Ponto(x, y, z);
}

void Camera::move(Camera::EIXO eixo, float distancia)
{
    if(eixo==Z)
    {
        float angulox = rotacao.x*3.141592/180;
        float anguloy = rotacao.y*3.141592/180;

        posicao.x+=-sin(anguloy)*distancia;
        posicao.y+=sin(angulox)*distancia;
        posicao.z+=cos(anguloy)*cos(angulox)*distancia;
    }
    else if(eixo==Y)
    {
        posicao.y+=distancia;
    }
    else if(eixo==X)
    {
        float anguloy = rotacao.y*3.141592/180;

        posicao.x+=cos(anguloy)*distancia;
        posicao.z+=sin(anguloy)*distancia;
    }
}

void Camera::rotate(Ponto rotacao)
{
	Ponto r=this->rotacao+rotacao;
	
	if(r.x>90) r.x=90;
	if(r.x<-90) r.x=-90;
	
	this->rotacao=r;
}

void Camera::rotate(float x, float y, float z)
{
	rotate(Ponto(x, y, z));
}
