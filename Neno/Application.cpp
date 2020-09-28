#include "Application.h"

namespace neno
{
    Engine* Application::mainEngine = nullptr;
    ApplicationConfig* Application::currentConfig = nullptr;
    int Application::frames = 0;
    int Application::timebase = 0;
    float Application::framesPerSecond = 0.0f;

    void Application::Render()
    {
        Color bufferColor = currentConfig->clearBufferColor;
        glClearColor(bufferColor.r, bufferColor.g, bufferColor.b, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glOrtho(0, currentConfig->screenWidth, 0, currentConfig->screenHeight, -1, 1);
        mainEngine->Render();
        glutSwapBuffers();
        //TODO Debug info
    }

    void Application::Resize(int width, int height)
    {
        Render();
    }

    void Application::Update()
    {
        mainEngine->Update(framesPerSecond);
    }

    void Application::Loop()
    {
        frames++;
        int time = glutGet(GLUT_ELAPSED_TIME);
        Update();
        Render();
        Keyboard::AfterUpdate();

        if (time - timebase > 1000)
        {
            framesPerSecond = frames * 1000.0 / (float)(time - timebase);
            timebase = time;
            frames = 0;
        }
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

    void Application::Start(Engine* engine, ApplicationConfig* config, int argc, char* argv[])
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

        delete currentConfig;
        currentConfig = config;

        StartWindow(argc, argv);
    }

    void Application::StartWindow(int argc, char* argv[])
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_RGBA);
        glutInitWindowSize(currentConfig->screenWidth, currentConfig->screenHeight);
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
        if (currentConfig->allowFullscreen)
            glutFullScreen();
        glutMainLoop();
    }
}