#include "pch.h"
#include "Application.h"

namespace Neno
{
    namespace Core
    {
        Engine* Application::mainEngine = nullptr;
        ApplicationConfig* Application::currentConfig = nullptr;
        GLFWwindow* Application::glfwWindow = nullptr;
        int Application::frames = 0;
        int Application::timebase = 0;
        float Application::framesPerSecond = 0.0f;
        SYSTEMTIME* Application::sysTime = nullptr;
        MEMORYSTATUSEX* Application::memInfo = nullptr;
        PROCESS_MEMORY_COUNTERS_EX* Application::pmc = nullptr;

        void Application::Render()
        {
            Color bufferColor = *currentConfig->clearBufferColor;
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bufferColor.r, bufferColor.g, bufferColor.b, 1.0);
            glLoadIdentity();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glOrtho(0, currentConfig->screenWidth, 0, currentConfig->screenHeight, -1, 1);
            glFlush();
            mainEngine->Render();
            glfwSwapBuffers(glfwWindow);
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
            double currentTime = glfwGetTime();
            frames++;
            Update();
            Render();
            Keyboard::AfterUpdate();
            Mouse::AfterUpdate();

            if (currentTime - timebase >= 1.0)
            {
                framesPerSecond = frames;
                frames = 0;
                timebase = currentTime;
            }
            glfwPollEvents();
        }

        void Application::ProcessKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            Keyboard::ProcessChar(key, action);
        }

        void Application::ProcessMouse(GLFWwindow* window, int button, int action, int mods)
        {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            Mouse::ProcessClick(button, action, xpos, ypos);
        }

        void Application::ProcessMousePos(GLFWwindow* window, double xpos, double ypos)
        {
            ProcessMouse(window, -1, 0, 0);
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
            Sound::Initialize();
            Font::Initialize();

            delete mainEngine;
            mainEngine = engine;

            delete currentConfig;
            currentConfig = config;

            StartWindow(argc, argv);
        }

        void Application::StartWindow(int argc, char* argv[])
        {
            SYSTEMTIME systemTimeEx;
            sysTime = &systemTimeEx;

            MEMORYSTATUSEX memoryInfo;
            memoryInfo.dwLength = sizeof(MEMORYSTATUSEX);
            memInfo = &memoryInfo;

            PROCESS_MEMORY_COUNTERS_EX pmcEx;
            pmc = &pmcEx;

            glfwInit();


            mainEngine->Create();

            glfwWindow = glfwCreateWindow(currentConfig->screenWidth, currentConfig->screenHeight, currentConfig->title, NULL, NULL);
            glfwMakeContextCurrent(glfwWindow);
            glewInit();

            glfwSetKeyCallback(glfwWindow, ProcessKeyboard);
            glfwSetMouseButtonCallback(glfwWindow, ProcessMouse);
            glfwSetCursorPosCallback(glfwWindow, ProcessMousePos);

            bool first = true;
            while (!glfwWindowShouldClose(glfwWindow))
            {
                Loop();
            }

            glfwTerminate();

            Font::Dispose();
            Sound::Dispose();
        }

        void Application::Stop()
        {
            if(glfwWindow != nullptr)
                glfwDestroyWindow(glfwWindow);
        }

        void Application::GLDebug()
        {
            GLfloat minFilter;
            GLfloat magFilter;
            GLfloat wrapS;
            GLfloat wrapT;

            glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &minFilter);
            glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, &magFilter);
            glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, &wrapS);
            glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, &wrapT);

            std::cout << "GL_TEXTURE_MIN_FILTER: " << GetFilterText(minFilter) << std::endl;
            std::cout << "GL_TEXTURE_MAG_FILTER: " << GetFilterText(magFilter) << std::endl;
            std::cout << "GL_TEXTURE_WRAP_S:     " << GetFilterText(wrapS) << std::endl;
            std::cout << "GL_TEXTURE_WRAP_T:     " << GetFilterText(wrapT) << std::endl;
        }

        const char* Application::GetFilterText(GLfloat filter)
        {
            if (filter == GL_LINEAR)
                return "GL_LINEAR";
            else if (filter == GL_REPEAT)
                return "GL_REPEAT";
            else if (filter == GL_NEAREST)
                return "GL_NEAREST";
            else if (filter == GL_NEAREST_MIPMAP_NEAREST)
                return "GL_NEAREST_MIPMAP_NEAREST";
            else if (filter == GL_NEAREST_MIPMAP_LINEAR)
                return "GL_NEAREST_MIPMAP_LINEAR";
            else if (filter == GL_LINEAR_MIPMAP_LINEAR)
                return "GL_LINEAR_MIPMAP_LINEAR";
            else if (filter == GL_LINEAR_MIPMAP_LINEAR)
                return "GL_LINEAR_MIPMAP_LINEAR";
            else if (filter == GL_CLAMP_TO_EDGE)
                return "GL_CLAMP_TO_EDGE";
            else if (filter == GL_CLAMP_TO_BORDER)
                return "GL_CLAMP_TO_BORDER";
            else if (filter == GL_MIRRORED_REPEAT)
                return "GL_MIRRORED_REPEAT";
            else if (filter == GL_MIRROR_CLAMP_TO_EDGE)
                return "GL_MIRROR_CLAMP_TO_EDGE";
            else if (filter == 0)
                return "Zero";
            else
                return ("Other " + std::to_string(filter)).c_str();
        }
    }
}