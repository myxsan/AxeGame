#include "raylib.h"

int main()
{
    int width{800};
    int height{450};
    InitWindow(width, height, "Test");
    

    //Circle Coordinates
    int circle_x{width / 2}, circle_y{height / 2};
    //Circle Size
    int circle_radius{25};
    //Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y + circle_radius};
    int b_circle_y{circle_y - circle_radius};

    //Axe Cooordinates
    int axe_x{400}, axe_y{0};
    int axe_length{50};
    //Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length / 2};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length / 2};

    int speed{5};
    int direction{10};
    
    bool coollision_with_axe = (b_axe_y >= u_circle_y) && 
                               (u_axe_y <= b_circle_y) && 
                               (r_axe_x >= l_axe_x) && 
                               (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(coollision_with_axe)
        {
            //Game End
            DrawText("Game Over!", 400, 200, 20, RED);
        }else
        {
            //Game Logic
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            //Update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //Update collision_with_axe
            coollision_with_axe = (b_axe_y >= u_circle_y) && 
                                  (u_axe_y <= b_circle_y) && 
                                  (r_axe_x >= l_axe_x) && 
                                  (l_axe_x <= r_circle_x);

            //Move the circle
            if(IsKeyDown(KEY_RIGHT) && circle_x < width){
                circle_x += speed;

            }if(IsKeyDown(KEY_LEFT) && circle_x > 0)
            {
                circle_x -= speed;

            }if(IsKeyDown(KEY_UP) && circle_y > 0)
            {
                circle_y -= speed;
                
            }if(IsKeyDown(KEY_DOWN) && circle_y < height)
            {
                circle_y += speed;
            }

            //Move the axe
            axe_y += direction;
            if(axe_y > 450 || axe_y < 0)
            {
                direction = -direction;
            }
        }


        EndDrawing();
    }
}