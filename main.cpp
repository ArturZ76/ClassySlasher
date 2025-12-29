#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    int WindowDimensions[2];
    WindowDimensions[0] = 386;
    WindowDimensions[1] = 386;

    InitWindow(WindowDimensions[0], WindowDimensions[1], "Classy Slasher");

    Texture2D background = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 MapPos{0.0f, 0.0f};
    const float mapScale = 4.0f;

    Character knight{WindowDimensions[0], WindowDimensions[1]};

    Prop props[4]{
        Prop{Vector2{600.0f, 300.0f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.0f, 500.0f}, LoadTexture("nature_tileset/Log.png")},
        Prop{Vector2{700.0f, 600.0f}, LoadTexture("nature_tileset/Bush.png")},
        Prop{Vector2{300.0f, 750.0f}, LoadTexture("nature_tileset/Sign.png")}};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        MapPos = Vector2Scale(knight.getWorldPos(), -1.0f);

        DrawTextureEx(background, MapPos, 0.0f, mapScale, WHITE);

        // draw the props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }

        knight.tick(GetFrameTime());

        // check map bounds
        if (knight.getWorldPos().x < 0.0f ||
            knight.getWorldPos().y < 0.0f ||
            knight.getWorldPos().x + WindowDimensions[0] > background.width * mapScale ||
            knight.getWorldPos().y + WindowDimensions[1] > background.height * mapScale)
        {
            knight.undoMovement();
        }

        //check collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
            {
                knight.undoMovement();
            }
        }

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}