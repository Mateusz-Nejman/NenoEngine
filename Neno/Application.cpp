#include "Application.h"
#include "Color.h"
#include <iostream>

namespace neno
{
    Engine* Application::mainEngine = nullptr;
    void Application::Render()
    {
        Color bufferColor(100, 149, 237);
        glClearColor(bufferColor.r, bufferColor.g, bufferColor.b, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glLoadIdentity();
        glOrtho(0, 800, 0, 600, -1, 1);
        mainEngine->Render();

        glFlush();
        glutSwapBuffers();
        //TODO Debug info
    }

    void Application::Resize(int width, int height)
    {
        glutReshapeWindow(800, 600);
        Render();
    }

    void Application::Start(Engine* engine, int argc, char* argv[])
    {
        if (engine == nullptr)
        {
            std::cout << "Engine cannot be null!" << std::endl;
            return;
        }

        delete mainEngine;
        mainEngine = engine;

        StartWindow(argc, argv);
    }

    void Application::StartWindow(int argc, char* argv[])
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Neno engine tests");
        glutDisplayFunc(Render);
        glutReshapeFunc(Resize);
        glutMainLoop();
    }
}