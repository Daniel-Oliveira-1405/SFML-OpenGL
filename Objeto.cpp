#include "Objeto.h"

Objeto::Objeto(Ponto posicao, Ponto rotacao, Ponto escala)
: posicao(posicao), rotacao(rotacao), escala(escala)
{
}

void Objeto::setPosition(Ponto posicao)
{
	this->posicao = posicao;
}

void Objeto::setRotation(Ponto rotacao)
{
	this->rotacao = rotacao;
}

void Objeto::setScale(Ponto escala)
{
	this->escala = escala;
}

Ponto Objeto::getPosition()
{
	return posicao;
}

Ponto Objeto::getRotation()
{
	return rotacao;
}

Ponto Objeto::getScale()
{
	return escala;
}

void Objeto::move(Ponto movimento)
{
	posicao += movimento;
}

void Objeto::rotate(Ponto rotacao)
{
	this->rotacao += rotacao;
}
