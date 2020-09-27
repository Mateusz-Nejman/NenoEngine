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

    void Application::Update()
    {
        mainEngine->Update();
    }

    void Application::Loop()
    {
        Update();
        Render();
        glutPostRedisplay();
    }

    void Application::ProcessKeyboard(unsigned char _char, int x, int y)
    {
        Keyboard::ProcessChar(_char, 1);
    }

    void Application::ProcessKeyboardReset(unsigned char _char, int x, int y)
    {
        Keyboard::ProcessChar(_char, 0);
    }

    void Application::ProcessMouse(int button, int state, int x, int y)
    {
        Mouse::ProcessClick(button, state, x, y);
    }

    void Application::Start(Engine* engine, int argc, char* argv[])
    {
        Keyboard::Initialize();
        Mouse::Initialize();
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
        glutDisplayFunc(Loop);
        glutReshapeFunc(Resize);
        glutKeyboardFunc(ProcessKeyboard);
        glutKeyboardUpFunc(ProcessKeyboardReset);
        glutMouseFunc(ProcessMouse);
        glutMainLoop();
    }
}