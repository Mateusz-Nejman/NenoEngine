#include "Application.h"
#include "Color.h"

namespace neno
{
    Engine* Application::mainEngine = nullptr;
    void Application::Render()
    {
        Color bufferColor = Color::CornflowerBlue;
        glClearColor(bufferColor.r, bufferColor.g, bufferColor.b, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glOrtho(0, 800, 0, 600, -1, 1);
        mainEngine->Render();
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
        Keyboard::AfterUpdate();
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

    void Application::ProcessKeyboardSpecial(int key, int x, int y)
    {
        Keyboard::ProcessChar(key+256, 1);
    }

    void Application::ProcessKeyboardSpecialReset(int key, int x, int y)
    {
        Keyboard::ProcessChar(key+256, 0);
    }

    void Application::ProcessMouse(int button, int state, int x, int y)
    {
        Mouse::ProcessClick(button, state, x, y);
    }

    void Application::ProcessMouseMove(int x, int y)
    {
        ProcessMouse(-1, 0, x, y);
    }

    void Application::Start(Engine* engine, int argc, char* argv[])
    {
        if (engine == nullptr)
        {
            std::cout << "Engine cannot be null!" << std::endl;
            return;
        }

        Keyboard::Initialize();
        Mouse::Initialize();

        delete mainEngine;
        mainEngine = engine;

        StartWindow(argc, argv);
    }

    void Application::StartWindow(int argc, char* argv[])
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_RGBA);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Neno engine tests");
        glutDisplayFunc(Loop);
        glutReshapeFunc(Resize);
        glutKeyboardFunc(ProcessKeyboard);
        glutKeyboardUpFunc(ProcessKeyboardReset);
        glutSpecialFunc(ProcessKeyboardSpecial);
        glutSpecialUpFunc(ProcessKeyboardSpecialReset);
        glutMotionFunc(ProcessMouseMove);
        glutPassiveMotionFunc(ProcessMouseMove);
        glutMouseFunc(ProcessMouse);
        glutMainLoop();
    }
}