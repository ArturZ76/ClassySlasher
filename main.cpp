#include "raylib.h"
#include "raymath.h"

int main()
{
    int WindowDimensions[2];
    WindowDimensions[0] = 512;
    WindowDimensions[1] = 384;

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Classy Slasher");

    Texture2D background = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 MapPos{0.0f, 0.0f};
    float Speed = 4.0f;

    Texture2D Knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 KnightPos{
        WindowDimensions[0]/2.0f - 4.0f * (0.5f * (float)Knight.width/6.0f), //() C style cast
        WindowDimensions[1]/2.0f - 4.0f * (0.5f * (float)Knight.height/6.0f)
    };


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 Direction{};
        if (IsKeyDown(KEY_A)) Direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) Direction.x += 1.0;
        if (IsKeyDown(KEY_W)) Direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) Direction.y += 1.0;

        if (Vector2Length(Direction) != 0.0)
        {
            MapPos = Vector2Subtract(MapPos, Vector2Scale(Vector2Normalize(Direction), Speed));
        }


        DrawTextureEx(background, MapPos, 0.0f, 4.0f, WHITE);

        //Character
        Rectangle source{0.0f, 0.0f, (float)Knight.width/6.0f, (float)Knight.height};
        Rectangle dest{KnightPos.x, KnightPos.y, 4.0f * (float)Knight.width/6.0f, 4.0f * (float)Knight.height};
        DrawTexturePro(Knight, source, dest, Vector2{}, 0.0f, WHITE);

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}