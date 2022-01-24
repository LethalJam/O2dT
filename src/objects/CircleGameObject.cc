#include "CircleGameObject.h"

namespace o2dt
{

    CircleGameObject::CircleGameObject(const sf::Texture &texture, b2Body *body, float radius)
        : GameObject(texture, body)
    {
        shape.m_radius = radius;
        graphicalShape.setRadius(radius);

        b2FixtureDef fixDef;
        fixDef.shape = &shape;
        fixDef.density = density;
        fixDef.friction = friction;

        body->CreateFixture(&fixDef);
    }

    CircleGameObject::CircleGameObject(const sf::Texture &texture, b2Body *body)
        : GameObject(texture, body)
    {
        float radius = sprite.getTexture()->getSize().y / 2;
        graphicalShape.setOrigin(radius, radius);
        shape.m_radius = radius;

        b2FixtureDef fixDef;
        fixDef.shape = &shape;
        fixDef.density = density;
        fixDef.friction = friction;

        body->CreateFixture(&fixDef);
    }

    sf::Shape &CircleGameObject::getBodyShape()
    {
        graphicalShape.setRadius(shape.m_radius);
        graphicalShape.setPosition(sf::Vector2f(body->GetPosition().x, body->GetPosition().y));

        return graphicalShape;
    }
}