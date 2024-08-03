#include "include/raylib.h"
#include <iostream>

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    // circle coords
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    Color circle_color{BLUE};

    // axe properties
    int axe_x{width / 2};
    int axe_y{circle_y / 2};
    int axe_length{50};
    Color axe_color{RED};
    int axe_movement{10};

    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    // collision
    bool hasCollided = ((b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x));

    SetTargetFPS(60);

    // game loop
    while (true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (hasCollided)
        {
            DrawText("Game Over", circle_x, circle_y, 20, RED);
        }
        else
        {
            // game logic begins

            // circle edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            // axe edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            hasCollided = ((b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x));

            DrawCircle(circle_x, circle_y, circle_radius, circle_color);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, axe_color);

            // Move the axe
            axe_y += axe_movement;
            if (axe_y > (height - axe_length) || axe_y < 0)
            {
                axe_movement = -axe_movement;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
        }
        // game logic ends
        EndDrawing();
    }
}
