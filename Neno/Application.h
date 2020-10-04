#ifndef APPLICATION_H
#define APPLICATION_H

#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <Psapi.h>
#include "ApplicationConfig.h"
#include "Color.h"
#include "Engine.h"
#include "Keyboard.h"
#include "Mouse.h"

#define MB 1048576

namespace neno
{
    class Application
    {
    public:
        static void Start(Engine* _engine, ApplicationConfig* config, int argc, char* argv[]);

    private:
        static MEMORYSTATUSEX* memInfo;
        static SYSTEMTIME* sysTime;
        static PROCESS_MEMORY_COUNTERS_EX* pmc;
        static Engine* mainEngine;
        static ApplicationConfig* currentConfig;
        static int frames;
        static int timebase;
        static float framesPerSecond;
        static GLFWwindow* glfwWindow;
        static void StartWindow(int argc, char* argv[]);
        static void Update();
        static void Render();
        static void Loop();
        static void Resize(int width, int heght);
        static void ProcessKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void ProcessMouse(GLFWwindow* window, int button, int action, int mods);
        static void ProcessMousePos(GLFWwindow* window, double xpos, double ypos);
        static void DrawDebugInfo();
    };
}

#endif // !APPLICATION_H