// Main.cpp
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "src\Renderer\Renderer.h"
#include "src\Time\Time.h"
#include "src\GameObject\Actor2D.h"
#include "src\Input\Input.h"
#include "src\Game\Game.h"
#include "src\Collision\CollisionManager.h"

#include "gl/gl.h"
#include "glut/glut.h"

Game* g_game = new Game();

void Update()
{
	Time::Update();

	g_game->Run();
	CollisionManager::Update();
	glPushMatrix();
	Renderer::DrawWorld();
	glPopMatrix();

}

int main(int argc, char *argv[])
{
	g_game->OneTimeInit();

	glutInit(&argc, argv);
	glutInitWindowSize(512, 512);
	glutInitDisplayMode(GLUT_STENCIL | GLUT_DEPTH | GLUT_DOUBLE);
	(void)glutCreateWindow("Mission Guy");
	glutDisplayFunc(&Renderer::DrawWorld);
	glutKeyboardFunc(&Input::CaptureInput);
	glutKeyboardUpFunc(&Input::ReleaseInput);
	glutIdleFunc(&Update);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-10., 10., -10., 10., 0., 20.);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_COLOR_MATERIAL);
    glutMainLoop();


	delete g_game;
	g_game = nullptr;

	return 0;
}

