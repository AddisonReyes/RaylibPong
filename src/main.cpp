#include <raylib.h>
#include <iostream>

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 800;

class Ball
{
public:
    float x, y;
    float speedX, speedY;
    int radius;

    void draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void update()
    {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius < 0)
        {
            speedY *= -1;
        }
        if (x + radius >= GetScreenWidth() || x - radius < 0)
        {
            speedX *= -1;
        }
    }
};

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game! My First Raylib game!!!");
    SetTargetFPS(60);

    Ball ball;
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7.0f;
    ball.speedY = 7.0f;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Update
        ball.update();

        // Drawing
        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        ball.draw();
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}