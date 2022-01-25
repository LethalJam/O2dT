#include "PlayerObject.h"
#include <algorithm>
#include <iostream>

namespace o2dt
{
    PlayerObject::PlayerObject(const sf::Texture &texture, b2Body *body)
        : PolygonGameObject(texture, body), GameObject(texture, body)
    {
    }

    void PlayerObject::updateInput(std::vector<std::string> inputs)
    {
        latestInputs = inputs;

        b2Vec2 vel;
        if (inputContains("moveLeft"))
        {
            vel.x = -walkSpeed;
        }
        if (inputContains("moveRight"))
        {
            vel.x = walkSpeed;
        }
        if (inputContains("moveUp"))
        {
            vel.y = -walkSpeed;
        }
        if (inputContains("moveDown"))
        {
            vel.y = walkSpeed;
        }
        body->SetLinearVelocity(vel);
        body->SetTransform(body->GetPosition(), 0.0f);
    }

    bool PlayerObject::inputContains(std::string inputName)
    {
        return std::find(latestInputs.begin(), latestInputs.end(), inputName) != latestInputs.end();
    }
}