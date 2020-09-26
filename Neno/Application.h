#include <GL/glut.h>
#include "Engine.h"
#include "Color.h"

namespace neno
{
    class Application
    {
    public:
        static Engine* mainEngine;
        static void Start(Engine* _engine, int argc, char* argv[]);

    private:
        static void StartWindow(int argc, char* argv[]);

        static void Render();
        static void Resize(int width, int heght);
    };
}