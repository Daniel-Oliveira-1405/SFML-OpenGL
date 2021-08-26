#include "Cubo.h"
#include<GL/gl.h>
#include<iostream>

using namespace std;

Cubo::Cubo(Ponto posicao, float tamanho)
{
	this->posicao = posicao;
	for(int i=0; i<6; i++) this->cores[i] = Cor(1, 0, 0, 1);
	for(int i=0; i<6; i++) this->texturas[i] = -1;
	this->escala = Ponto(tamanho, tamanho, tamanho);
}

Cubo::Cubo(Cubo& cubo)
{
	posicao = cubo.getPosition();
	rotacao = cubo.getRotation();
	escala = cubo.getScale();
	
	for(int i=0; i<6; i++) setFaceColor(i, cubo.getFaceColor(i));
	for(int i=0; i<6; i++) setFaceTexture(i, -cubo.getFaceTexture(i));
}

void Cubo::operator=(Cubo& cubo)
{
	posicao = cubo.getPosition();
	rotacao = cubo.getRotation();
	escala = cubo.getScale();
	
	for(int i=0; i<6; i++) setFaceColor(i, cubo.getFaceColor(i));
	for(int i=0; i<6; i++) setFaceTexture(i, -cubo.getFaceTexture(i));
}

void Cubo::desenhar(Camera& camera)
{
	glLoadIdentity();
	
	glPushMatrix();

	Ponto camRot = camera.getRotation();
	Ponto translated = posicao-camera.getPosition();

	glRotatef(camRot.x, 1, 0, 0);
	glRotatef(camRot.y, 0, 1, 0);
	glTranslatef(translated.x, translated.y, translated.z);
	glRotatef(rotacao.x, 1, 0, 0);
	glRotatef(rotacao.y, 0, 1, 0);
	glRotatef(rotacao.z, 0, 0, 1);
	
	Ponto p[8];

	float x = escala.x/2;
	float y = escala.y/2;
	float z = escala.z/2;

	p[0] = Ponto( x, -y,  z);
	p[1] = Ponto( x,  y,  z);
	p[2] = Ponto(-x,  y,  z);
	p[3] = Ponto(-x, -y,  z);
	p[4] = Ponto( x, -y, -z);
	p[5] = Ponto( x,  y, -z);
	p[6] = Ponto(-x,  y, -z);
	p[7] = Ponto(-x, -y, -z);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if(texturas[FRONT]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[FRONT]);
	glBegin(GL_QUADS);
	
	glColor4fv(&cores[FRONT].r);
	glTexCoord2f(0, 0); glVertex3fv(&p[0].x);
	glTexCoord2f(0, 1); glVertex3fv(&p[1].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[2].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[3].x);
	
	glEnd();
	if(texturas[BACK]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[BACK]);
	glBegin(GL_QUADS);

	glColor4fv(&cores[BACK].r);
	glTexCoord2f(0, 0); glVertex3fv(&p[7].x);
	glTexCoord2f(0, 1); glVertex3fv(&p[6].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[5].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[4].x);

	glEnd();
	if(texturas[LEFT]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[LEFT]);
	glBegin(GL_QUADS);

	glColor4fv(&cores[LEFT].r);
	glTexCoord2f(0, 1); glVertex3fv(&p[5].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[1].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[0].x);
	glTexCoord2f(0, 0); glVertex3fv(&p[4].x);

	glEnd();
	if(texturas[RIGHT]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[RIGHT]);
	glBegin(GL_QUADS);

	glColor4fv(&cores[RIGHT].r);
	glTexCoord2f(0, 0); glVertex3fv(&p[3].x);
	glTexCoord2f(0, 1); glVertex3fv(&p[2].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[6].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[7].x);

	glEnd();
	if(texturas[UP]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[UP]);
	glBegin(GL_QUADS);

	glColor4fv(&cores[UP].r);
	glTexCoord2f(0, 0); glVertex3fv(&p[1].x);
	glTexCoord2f(0, 1); glVertex3fv(&p[5].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[6].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[2].x);

	glEnd();
	if(texturas[DOWN]!=-1) glBindTexture(GL_TEXTURE_2D, texturas[DOWN]);
	glBegin(GL_QUADS);

	glColor4fv(&cores[DOWN].r);
	glTexCoord2f(0, 0); glVertex3fv(&p[7].x);
	glTexCoord2f(0, 1); glVertex3fv(&p[4].x);
	glTexCoord2f(1, 1); glVertex3fv(&p[0].x);
	glTexCoord2f(1, 0); glVertex3fv(&p[3].x);

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glPopMatrix();
}

void Cubo::setFaceColor(int face, Cor c)
{
	cores[face] = c;
}

Cor Cubo::getFaceColor(int face)
{
	return cores[face];
}

void Cubo::setFaceTexture(int face, int texture)
{
	this->texturas[face] = texture;
}

int Cubo::getFaceTexture(int face)
{
	return this->texturas[face];
}
