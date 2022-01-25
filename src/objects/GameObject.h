#ifndef O2DT_GAME_OBJECT
#define O2DT_GAME_OBJECT

#include <memory>

#include <SFML/Graphics.hpp>
#include <box2d/b2_body.h>

namespace o2dt
{
    class GameObject
    {
    public:
        GameObject(const sf::Texture &texture, b2Body *body);
        ~GameObject();

        // sets
        void setTexture(const sf::Texture &texture);
        void setPositionAndAngle(b2Vec2 pos, float angle);
        void setDensity(float density);
        void setFriction(float friction);

        // gets
        const sf::Sprite &getSprite();
        virtual sf::Shape &getBodyShape() = 0;

    protected:
        sf::Sprite sprite;
        GameObject();

        // Physics members
        b2Body *body;
        float density = 1.0f;
        float friction = 0.3f;
    };
}

#endif