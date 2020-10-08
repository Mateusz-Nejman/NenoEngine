// Neno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Neno/Core/Neno.h>
#include "TestEngine.h"

using namespace Neno;
using namespace Neno::Core;
int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";
    TestEngine* engine = new TestEngine();
    ApplicationConfig* config = new ApplicationConfig("Neno TestEngine", 1024, 768, false, true, &Color::CornflowerBlue);
    Application::Start(engine, config, argc, argv);

    delete engine;
    delete config;
    engine = nullptr;
    config = nullptr;

    system("PAUSE");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
