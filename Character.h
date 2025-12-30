#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winheight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRect; }
    float getHealth() { return health; }
    void takeDamage(float damage);

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRect{};
    float health{100.0f};
};

#endif