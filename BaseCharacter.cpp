#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrames)
            frame = 0;
    }

        if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPOs + directions
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.0f ? RightLeft = -1.0f : RightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // Character
    Rectangle source{frame * (float)texture.width / 6.0f, 0.0f, RightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}