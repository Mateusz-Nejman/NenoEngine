#include <GL/glut.h>
#include "Engine.h"
#include "Color.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace neno
{
    class Application
    {
    public:
        static Engine* mainEngine;
        static void Start(Engine* _engine, int argc, char* argv[]);

    private:
        static void StartWindow(int argc, char* argv[]);
        static void Update();
        static void Render();
        static void Loop();
        static void Resize(int width, int heght);
        static void ProcessKeyboard(unsigned char _char, int x, int y);
        static void ProcessKeyboardReset(unsigned char _char, int x, int y);
        static void ProcessMouse(int button, int state, int x, int y);
    };
}