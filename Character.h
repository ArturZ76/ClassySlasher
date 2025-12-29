#include "raylib.h"

class Character
{
public:
    Character();
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int WinWidth, int WinHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.0f / 12.0f};
    float speed{4.0f};
    float RightLeft{1.0f};
    float width{};
    float height{};
};