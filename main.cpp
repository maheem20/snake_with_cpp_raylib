#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{

    cout << "Starting game..." << endl;
    InitWindow(750, 750, "Retro Snake");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}