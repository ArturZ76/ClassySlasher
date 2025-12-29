#include "raylib.h"
#include "raymath.h"
#include "Character.h"


int main()
{
    int WindowDimensions[2];
    WindowDimensions[0] = 386;
    WindowDimensions[1] = 386;

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Classy Slasher");

    Texture2D background = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 MapPos{0.0f, 0.0f};
    const float mapScale = 4.0f;

    SetTargetFPS(60);

    Character knight;
    knight.setScreenPos(WindowDimensions[0], WindowDimensions[1]);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        MapPos = Vector2Scale(knight.getWorldPos(), -1.0f);

        DrawTextureEx(background, MapPos, 0.0f, mapScale, WHITE);
        knight.tick(GetFrameTime());

        //check map bounds
        if (knight.getWorldPos().x < 0.0f || 
            knight.getWorldPos().y < 0.0f ||
            knight.getWorldPos().x + WindowDimensions[0] > background.width * mapScale||
            knight.getWorldPos().y + WindowDimensions[1] > background.height * mapScale)
            {
                knight.undoMovement();
            }

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}