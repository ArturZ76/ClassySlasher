#include "Character.h"
#include "raylib.h"
#include "raymath.h"

Character::Character(int winWidth, int winheight)
{
    width = texture.width / maxFrames;
    height = texture.height;
    screenPos = {
        static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(winheight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);
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
}
