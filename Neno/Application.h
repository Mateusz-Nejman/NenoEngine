#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glut.h>
#include <iostream>
#include "ApplicationConfig.h"
#include "Color.h"
#include "Engine.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace neno
{
    class Application
    {
    public:
        static Engine* mainEngine;
        static ApplicationConfig* currentConfig;
        static void Start(Engine* _engine, ApplicationConfig* config, int argc, char* argv[]);

    private:
        static void StartWindow(int argc, char* argv[]);
        static void Update();
        static void Render();
        static void Loop();
        static void Resize(int width, int heght);
        static void ProcessKeyboard(unsigned char _char, int x, int y);
        static void ProcessKeyboardReset(unsigned char _char, int x, int y);
        static void ProcessKeyboardSpecial(int key, int x, int y);
        static void ProcessKeyboardSpecialReset(int key, int x, int y);
        static void ProcessMouse(int button, int state, int x, int y);
        static void ProcessMouseMove(int x, int y);
    };
}

#endif // !APPLICATION_H