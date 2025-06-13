#include <raylib.h>
#include <iostream>

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 800;

int main()
{
    InitWindow(screenWidth, screenHeight, "My Pong Game!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}