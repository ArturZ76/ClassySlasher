#include "Character.h"
#include "raylib.h"
#include "raymath.h"

Character::Character()
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Character::setScreenPos(int WinWidth, int WinHeight)
{
    screenPos = {
        WinWidth / 2.0f - 4.0f * (0.5f * width),
        WinHeight / 2.0f - 4.0f * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    Vector2 Direction{};
    if (IsKeyDown(KEY_A))
        Direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        Direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        Direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        Direction.y += 1.0;

    if (Vector2Length(Direction) != 0.0)
    {
        // set worldPos = worldPOs + directions
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(Direction), speed));
        Direction.x < 0.0f ? RightLeft = -1.0f : RightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrames)
            frame = 0;
    }

    // Character
    Rectangle source{frame * (float)texture.width / 6.0f, 0.0f, RightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}