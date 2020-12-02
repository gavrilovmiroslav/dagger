#include "plight_tilemaps_initialization.h"

#include "core/graphics/sprite.h"

using namespace dagger;

Entity CreateFloor(Registry& reg_, INT32 x_, INT32 y_)
{
        Entity entity = reg_.create();
        auto& sprite = reg_.emplace<Sprite>(entity);
        sprite.position = { x_ * 16, y_ * 16, 90 };
        float mod = (float)rand() / RAND_MAX;
        if (mod <= 0.6) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_1");
        }
        else if (0.6 < mod <= 0.7) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_2");
        }
        else if (0.7 < mod <= 0.8) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_3");
        }
        else if (0.8 < mod <= 0.85) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_4");
        }
        else if (0.85 < mod <= 0.9) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_5");
        }
        else if (0.90 < mod <= 0.925) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_6");
        }
        else if (0.925 < mod <= 0.95) {
            AssignSprite(sprite, "spritesheets:dungeon:floor_7");
        }
        else {
            AssignSprite(sprite, "spritesheets:dungeon:floor_8");
        }

        return entity;   
}

Entity CreateBlackBackground(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 90 };
    AssignSprite(sprite, "EmptyWhitePixel");
    sprite.color = { 0.f,0.f,0.f,1.f };
    sprite.size = { 16,16 };
    return entity;
}

Entity CreateEmpty(Registry& reg_, INT32 x_, INT32 y_)
{
    return Entity();
}

Entity CreateWallSideTopLeft(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_top_left");
    
    return entity;
}

Entity CreateWallSideTopRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_top_right");
    return entity;
}

Entity CreateWallCornerBottomLeft(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_corner_bottom_left");
    return entity;
}

Entity CreateWallCornerBottomRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_corner_bottom_right");
    return entity;
}
Entity CreateWallCornerMidRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_inner_corner_mid_rigth");
    return entity;
}

Entity CreateWallSideMidLeft(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_mid_left");
    return entity;
}
Entity CreateWallCornerRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_corner_right");
    return entity;
}

Entity CreateWallCornerLeft(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_corner_left");
    return entity;
}

Entity CreateFrontWall(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    float mod = (float)rand() / RAND_MAX;
    if (mod <= 0.33) {
        AssignSprite(sprite, "spritesheets:dungeon:wall_top_left");
    }
    else if (0.33 < mod <= 0.66) {
        AssignSprite(sprite, "spritesheets:dungeon:wall_top_mid");
    }
    else {
        AssignSprite(sprite, "spritesheets:dungeon:wall_top_right");
    }
    return entity;
}

Entity CreateWallMid(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
   
    float mod = (float)rand() / RAND_MAX;
    if (mod <= 0.33) {
        AssignSprite(sprite, "spritesheets:dungeon:wall_left");
    }
    else if (0.33 < mod <= 0.66) {
        AssignSprite(sprite, "spritesheets:dungeon:wall_mid");
    }
    else {
        AssignSprite(sprite, "spritesheets:dungeon:wall_right");
    }
    return entity;
}

Entity CreateWallSideFrontLeft(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_front_left");

    return entity;
}

Entity CreateWallSideFrontRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_front_right");

    return entity;
}

Entity CreateSideWallMidRight(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_side_mid_right");
    return entity;
}

Entity CreateWallColumn(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_coulmn_base");

    Entity entity2 = reg_.create();
    auto& sprite2 = reg_.emplace<Sprite>(entity2);
    sprite2.position = { x_ * 16, (y_+1) * 16, 89 };
    AssignSprite(sprite2, "spritesheets:dungeon:column_mid");

    Entity entity3 = reg_.create();
    auto& sprite3 = reg_.emplace<Sprite>(entity3);
    sprite3.position = { x_ * 16, (y_ + 2) * 16, 89 };
    AssignSprite(sprite3, "spritesheets:dungeon:column_top");

    return entity;
}

Entity CreateWallBannerBlue(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_banner_blue");
    return entity;
}

Entity CreateWallBannerRed(Registry& reg_, INT32 x_, INT32 y_)
{
    Entity entity = reg_.create();
    auto& sprite = reg_.emplace<Sprite>(entity);
    sprite.position = { x_ * 16, y_ * 16, 89 };
    AssignSprite(sprite, "spritesheets:dungeon:wall_banner_red");
    return entity;
}
