#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

float cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};

    void Draw()
    {
        for (int i = 0; i < body.size(); i++)
        {
            int x = body[i].x;
            int y = body[i].y;
            Rectangle segment = Rectangle{x * cellSize, y * cellSize, cellSize, cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }
};

class Food
{
public:
    Vector2 position = {5, 6};
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos();
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }
};

class Game
{
};

int main()
{

    cout << "Starting game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (eventTriggered(0.2))
        {
            snake.Update();
        }

        if (IsKeyPressed(KEY_UP) && snake.direction.y != 1)
        {
            snake.direction = {0, -1};
        }
        if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
        {
            snake.direction = {0, 1};
        }
        if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
        {
            snake.direction = {-1, 0};
        }
        if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
        {
            snake.direction = {1, 0};
        }

        ClearBackground(green);
        food.Draw();
        snake.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}