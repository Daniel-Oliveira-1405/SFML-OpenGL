#include<SFML/Graphics.hpp>
#include<SFML/OpenGL.hpp>
#include<GL/glext.h>
#include<windows.h>
#include<GL/glu.h>
#include<iostream>
#include<sstream>

#include "Cubo.h"

using namespace std;
using namespace sf;

void carregarTextura(string filename, int id, int param)
{
	Image img;
	if(!img.loadFromFile(filename))
	{
		cout << "Nao foi possivel carregar a textura " << filename << ".\n";
	}
	else
	{
		img.flipVertically();
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, param);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, param);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glClearColor(0, 0, 0, 1);
}

int main()
{
	ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel=8;
	settings.majorVersion=3;
	settings.minorVersion=3;
	RenderWindow window(VideoMode(800, 600), "SFML & OpenGL", Style::Default, settings);
	
	ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
	
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	
	Camera camera(Ponto(0, 0, 5), Ponto(), 60);
	
	init();

	Cubo cubo(Ponto(0, 0, 0), 1);
	cubo.setFaceColor(FRONT, Cor(0, 0, 1, 1));
	cubo.setFaceColor(BACK , Cor(0, 1, 0, 1));
	cubo.setFaceColor(RIGHT, Cor(1, 0, 0, 1));
	cubo.setFaceColor(LEFT , Cor(1, 0.5, 0, 1));
	cubo.setFaceColor(UP   , Cor(1, 1, 0, 1));
	cubo.setFaceColor(DOWN,  Cor(1, 1, 1, 1));
	
	unsigned int id[3];
	glGenTextures(3, id);
	carregarTextura("resources/terra.jpg", id[0], GL_NEAREST);
	carregarTextura("resources/grass.jpg", id[1], GL_NEAREST);
	carregarTextura("resources/terraLado.jpg", id[2], GL_NEAREST);

	cubo.setFaceTexture(FRONT, id[2]);
	cubo.setFaceTexture(BACK , id[2]);
	cubo.setFaceTexture(RIGHT, id[2]);
	cubo.setFaceTexture(LEFT , id[2]);
	cubo.setFaceTexture(UP   , id[1]);
	cubo.setFaceTexture(DOWN , id[0]);

	auto resize = [camera](int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(camera.getCampoDeVisao(), (float)w/(float)h, 0.01, 1000);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	};
	
	Clock clock;
	
	Font fonte;
	fonte.loadFromFile("resources/sansation.ttf");
	
	Text t;
	t.setCharacterSize(24);
	t.setPosition(20, 20);
	t.setFillColor(Color::White);
	
	resize(window.getSize().x, window.getSize().y);
	
	Vector2i centro(window.getSize().x/2, window.getSize().y/2);
	Mouse::setPosition(centro, window);
	
	float deltatime;
	bool paused=false;

	while(window.isOpen())
	{
		Event e;
		while(window.pollEvent(e))
		{
			if(e.type == Event::Closed)
				window.close();
			if(e.type == Event::Resized)
			{
				float w = e.size.width, h=e.size.height;
				resize(w, h);
				
				window.setView(View(FloatRect(0, 0, e.size.width, e.size.height)));
			}
			if(e.type == Event::KeyPressed)
			{
				if(e.key.code == Keyboard::Escape)
					window.close();
				if(e.key.code == Keyboard::Space)
					paused=!paused;
			}
			if(e.type == Event::MouseMoved || e.type == Event::MouseLeft && Mouse::getPosition(window)!=centro)
			{
				Vector2i move = Mouse::getPosition(window)-centro;

				float s=0.25;

				camera.rotate(move.y*s, move.x*s, 0);
				
				Mouse::setPosition(centro, window);
			}
		}
		
		deltatime = clock.restart().asSeconds();
		float fps = 1/deltatime;
		
		float velo=5;
		
		using K = Keyboard;
		if(K::isKeyPressed(K::LShift) || K::isKeyPressed(K::RShift))
			velo*=3;
		else velo/=3;

		if(Keyboard::isKeyPressed(Keyboard::Left))
			camera.move(Camera::X, -velo*deltatime);
		if(Keyboard::isKeyPressed(Keyboard::Right))
			camera.move(Camera::X,  velo*deltatime);
		if(Keyboard::isKeyPressed(Keyboard::Up))
			camera.move(Camera::Z, -velo*deltatime);
		if(Keyboard::isKeyPressed(Keyboard::Down))
			camera.move(Camera::Z,  velo*deltatime);
		if(Keyboard::isKeyPressed(Keyboard::S))
			camera.move(Camera::Y, -velo*deltatime);
		if(Keyboard::isKeyPressed(Keyboard::W))
			camera.move(Camera::Y,  velo*deltatime);
		
		t.setFont(fonte);
		stringstream ss;
		ss << fps;
		t.setString(ss.str());

		if(!paused)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			cubo.desenhar(camera);
			//cubo.move(Ponto(0, deltatime, 0));
			//cubo.rotate(Ponto(0, 90*deltatime, 0));
			
			glPushMatrix();
			
			Ponto m = Ponto()-camera.getPosition();
			Ponto r = camera.getRotation();
			glRotatef(r.x, 1, 0, 0);
			glRotatef(r.y, 0, 1, 0);
			glTranslatef(m.x, m.y, m.z);
			
			glBegin(GL_LINES);
			
			glColor3f(1, 0, 0);
			glVertex3f(-1000, 0, 0);
			glVertex3f( 1000, 0, 0);

			glColor3f(0, 1, 0);
			glVertex3f(0, -1000, 0);
			glVertex3f(0,  1000, 0);
			
			glColor3f(0, 0, 1);
			glVertex3f(0, 0, -1000);
			glVertex3f(0, 0,  1000);
			
			glEnd();
			
			glPopMatrix();

			//window.clear();
			window.pushGLStates();

			window.draw(t);

			window.popGLStates();
			window.display();
		}
		
		glFlush();
	}
	glDeleteTextures(3, id);
}
