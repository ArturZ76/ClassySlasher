#ifndef BASE_CHARACTER_H // prevent to load this class many times in main and create bug
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{

public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; };
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0; //pure virtual function

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.0f / 12.0f};
    float speed{4.0f};
    float RightLeft{1.0f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};
private:
};

#endif
