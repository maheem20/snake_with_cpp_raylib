#include <iostream>
#include <raylib.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int main()
{

    cout << "Starting game..." << endl;
    InitWindow(750, 750, "Retro Snake");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(green);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}