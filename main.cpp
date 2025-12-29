#include "raylib.h"
#include "raymath.h"
#include "Character.h"


int main()
{
    int WindowDimensions[2];
    WindowDimensions[0] = 512;
    WindowDimensions[1] = 384;

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Classy Slasher");

    Texture2D background = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 MapPos{0.0f, 0.0f};

    SetTargetFPS(60);

    Character knight;
    knight.setScreenPos(WindowDimensions[0], WindowDimensions[1]);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        MapPos = Vector2Scale(knight.getWorldPos(), -1.0f);

        DrawTextureEx(background, MapPos, 0.0f, 4.0f, WHITE);
        knight.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}