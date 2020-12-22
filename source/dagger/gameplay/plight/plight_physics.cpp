#include "plight_physics.h"
#include "plight_collisions.h"

#include "core/engine.h"
#include "core/game/transforms.h"

#include "gameplay/plight/plight_controller.h"

#include <algorithm>    

using namespace plight;
using namespace dagger;

void plight::PhysicsSystem::Run()
{
    auto view = Engine::Registry().view<PlightCollision, Transform, PhysicsObject>();
    auto it = view.begin();

    auto& physics = view.get<PhysicsObject>(*it);
    if (!physics.is_static) {
        while (it != view.end())
        {
            auto& collision = view.get<PlightCollision>(*it);
            auto& transform = view.get<Transform>(*it);

            auto it2 = collision.colidedWith.begin();
            while (it2 != collision.colidedWith.end())
            {
                bool skip = false;
                if (Engine::Registry().has<PhysicsObject>(*it2)) {
                    auto& other_physics = view.get<PhysicsObject>(*it2);
                    bool has = false;
                    for (int group : other_physics.collision_groups) {
                        if (std::find(physics.my_groups.begin(), physics.my_groups.end(), group) != physics.my_groups.end()) {
                            has = true;
                            break;
                        }
                    }
                    if (Engine::Registry().has<PlightCharacterController>(*it)) {
                        auto& character = Engine::Registry().get<PlightCharacterController>(*it);
                        if (!character.running) {
                            has = false;
                        }
                    }
                    if (has) {
                        auto& other_transform = view.get<Transform>(*it2);
                        auto& other_collision = view.get<PlightCollision>(*it2);
                        ResolveCollision(transform.position, collision, *it, other_transform.position, other_collision, it2);
                        skip = true;
                    }
                }
                if (!skip) it2++;
            }
            it++;
        }
    }
}

void plight::PhysicsSystem::ResolveCollision(Vector3& pos_, PlightCollision& myCol_, entt::entity my_, Vector3& posOther_, PlightCollision& otherCol_, std::list<entt::entity>::iterator& other_)
{
    // Moves the coliding object out of the other coliding object & increments it2
   Vector2 sides = myCol_.GetCollisionSides(pos_, otherCol_, posOther_);
   bool moveBoth = false;
   Float32 newPosx, newPosy, newOtherPosx, newOtherPosy;
   if (Engine::Registry().has<PlightCharacterController>(*other_)) {
       moveBoth = true;
   }

    if (sides.x != 0) {
        if (sides.x == 1) {
            newPosx = posOther_.x - myCol_.size.x - 1;
            if (moveBoth) {
                newOtherPosx = pos_.x + otherCol_.size.x + 1;
            }
            pos_.x = newPosx;
            posOther_.x = newOtherPosx;
        }
        else {
            newPosx = posOther_.x + otherCol_.size.x + 1;
            if (moveBoth) {
                newOtherPosx = pos_.x - otherCol_.size.x - 1;
                posOther_.x = newOtherPosx;
            }
            pos_.x = newPosx;        
        }
    }
    if (sides.y != 0) {
        if (sides.y == 1) {
            newPosy = posOther_.y - myCol_.size.y - 1;
            if (moveBoth) {
                newOtherPosy = pos_.y + otherCol_.size.y + 1;
                posOther_.y = newOtherPosy;
            }
            pos_.y = newPosy;
        }
        else {
            newPosy = posOther_.y + otherCol_.size.y + 1;
            if (moveBoth) {
                newOtherPosy = pos_.y - otherCol_.size.y - 1;
                posOther_.y = newOtherPosy;
            }
            pos_.y = newPosy;
        }
    }

    other_=myCol_.colidedWith.erase(other_);
    if(myCol_.colidedWith.size() == 0) myCol_.colided = false;

    otherCol_.colidedWith.remove(my_);
    if (otherCol_.colidedWith.size() == 0) otherCol_.colided = false;
}

