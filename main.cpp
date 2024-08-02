#include "include/raylib.h"
#include <iostream>

int main()
{
    // window dimensions
    int width{350};
    int height{200};
    InitWindow(width, height, "Window");

    // circle coordinates
    int circle_x{175};
    int circle_y{100};

    SetTargetFPS(60);

    while (true)
    {

        BeginDrawing();
        ClearBackground(RED);

        // game logic begins

        DrawCircle(circle_x, circle_y, 25, BLUE);

        if (IsKeyDown(KEY_D))
        {
            circle_x += 10;
        }
        // game logic ends
        EndDrawing();
    }
}
