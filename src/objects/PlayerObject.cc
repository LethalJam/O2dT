#include "PlayerObject.h"
#include <algorithm>
#include <iostream>

namespace o2dt
{
    PlayerObject::PlayerObject(const sf::Texture &texture, b2Body *body)
        : PolygonGameObject(texture, body, 60 / 2, 100 / 2), GameObject(texture, body),
          animator(o2dt::SpriteSheetAnimator(animationSpeed, sprite, 60, 100, 3, 3))
    {
        sprite.setOrigin(sf::Vector2f(60 / 2, 100 / 2));
    }

    void PlayerObject::updateInput(std::vector<std::string> inputs)
    {
        latestInputs = inputs;
        // pMovStatePrev = pMovState; // TODO: Remove maybe??

        b2Vec2 vel = b2Vec2(0.0f, 0.0f);
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

        if (vel.LengthSquared() > 0.0f)
        {
            pMovState = MovementState::WALKING;
        }
        else
        {
            pMovState = MovementState::IDLE;
        }

        if (inputContains("sneak"))
        {
            vel *= (1.0f / sprintModifier);
            animator.setAnimationSpeed(animationSpeed * (sprintModifier));
            sf::Color c = sprite.getColor();
            c.a = sf::Uint8(100);
            sprite.setColor(c);
            if (pMovState == MovementState::WALKING)
            {
                pMovState = MovementState::SNEAKING;
            }
        }
        else if (inputContains("sprint"))
        {
            vel *= sprintModifier;
            animator.setAnimationSpeed(animationSpeed * (1.0f / sprintModifier));
            sf::Color c = sprite.getColor();
            c.a = sf::Uint8(255);
            sprite.setColor(c);
            if (pMovState == MovementState::WALKING)
            {
                pMovState = MovementState::SPRINTING;
            }
        }
        else
        {
            animator.setAnimationSpeed(animationSpeed);
            sf::Color c = sprite.getColor();
            c.a = sf::Uint8(255);
            sprite.setColor(c);
        }
        animate(vel);

        body->SetLinearVelocity(vel);
        body->SetTransform(body->GetPosition(), 0.0f);
    }

    const MovementState &PlayerObject::getMovementState()
    {
        return pMovState;
    }
    const PlayerState &PlayerObject::getPlayerState()
    {
        return pState;
    }

    bool PlayerObject::inputContains(std::string inputName)
    {
        return std::find(latestInputs.begin(), latestInputs.end(), inputName) != latestInputs.end();
    }

    void PlayerObject::animate(b2Vec2 &vel)
    {
        if (vel.y > 0)
        {
            animator.setAnimation(sf::Vector2i(1, 1), sf::Vector2i(2, 1));
        }
        else if (vel.y < 0)
        {
            animator.setAnimation(sf::Vector2i(1, 2), sf::Vector2i(2, 2));
        }
        else if (vel.x > 0)
        {
            sprite.setScale(sf::Vector2f(1.0f, 1.0f));
            animator.setAnimation(sf::Vector2i(1, 0), sf::Vector2i(2, 0));
        }
        else if (vel.x < 0)
        {
            sprite.setScale(sf::Vector2f(-1.0f, 1.0f));
            animator.setAnimation(sf::Vector2i(1, 0), sf::Vector2i(2, 0));
        }

        if (pMovState == MovementState::IDLE)
        {
            animator.setAnimation(sf::Vector2i(0, 0), sf::Vector2i(0, 0)); // Idle Frame
        }
    }
}