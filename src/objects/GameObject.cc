#include "GameObject.h"
#include "../helpers/mathDefinitions.h"

namespace o2dt
{
    GameObject::GameObject()
    {
    }
    GameObject::GameObject(const sf::Texture &texture, b2Body *body)
    {
        sprite.setTexture(texture, true); // Don't resize to texture assuming no spritesheet.
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        this->body = body;
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::setTexture(const sf::Texture &texture)
    {
        sprite.setTexture(texture);
    }
    void GameObject::setPositionAndAngle(b2Vec2 pos, float angle)
    {
        body->SetTransform(pos, angle);
    }
    void GameObject::setDensity(float density)
    {
        this->density = density;
    }
    void GameObject::setFriction(float friction)
    {
        this->friction = friction;
    }

    const sf::Sprite &GameObject::getSprite()
    {
        sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
        sprite.setRotation(MathDefinitions::radianToDegree(body->GetAngle()));
        return sprite;
    }
}