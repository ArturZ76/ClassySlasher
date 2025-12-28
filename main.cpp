#include "raylib.h"

int main()
{
    int WindowDimensions[2];
    WindowDimensions[0] = 384;
    WindowDimensions[1] = 384;

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Classy Slasher");

    Texture2D background = LoadTexture("nature_tileset/WorldMap.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 bgPos{0.0f, 0.0f};
        DrawTextureEx(background, bgPos, 0.0f, 4.0f, WHITE);

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}