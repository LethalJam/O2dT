#include "PolygonGameObject.h"
#include "../helpers/mathDefinitions.h"
#include <math.h>

namespace o2dt
{

    PolygonGameObject::PolygonGameObject(const sf::Texture &texture, b2Body *body, float width, float height)
        : GameObject(texture, body) // Creates the body
    {
        shape.SetAsBox(width, height);

        b2FixtureDef fixDef;
        fixDef.shape = &shape;
        fixDef.density = density;
        fixDef.friction = friction;

        body->CreateFixture(&fixDef);
        isBox = true;
    }

    PolygonGameObject::PolygonGameObject(const sf::Texture &texture, b2Body *body)
        : GameObject(texture, body) // Creates the body
    {
        float sizeX = sprite.getTexture()->getSize().x / 2;
        float sizeY = sprite.getTexture()->getSize().y / 2;
        shape.SetAsBox(sizeX, sizeY);

        b2FixtureDef fixDef;
        fixDef.shape = &shape;
        fixDef.density = density;
        fixDef.friction = friction;

        body->CreateFixture(&fixDef);
        isBox = true;
    }

    sf::Shape &PolygonGameObject::getBodyShape()
    {
        graphicalShape.setPointCount(shape.m_count);
        for (int i = 0; i < shape.m_count; i++)
        {
            b2Vec2 p = shape.m_vertices[i];
            graphicalShape.setPoint(i, sf::Vector2f(p.x, p.y));
        }
        graphicalShape.setPosition(sf::Vector2f(body->GetPosition().x, body->GetPosition().y));
        graphicalShape.setRotation(MathDefinitions::radianToDegree(body->GetAngle()));

        return graphicalShape;
    }

}