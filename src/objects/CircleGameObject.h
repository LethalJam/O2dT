#ifndef O2DT_CIRCLE_GAME_OBJECT
#define O2DT_CIRCLE_GAME_OBJECT

#include <box2d/b2_circle_shape.h>
#include <box2d/b2_fixture.h>
#include "GameObject.h"

namespace o2dt
{
    class CircleGameObject : public virtual GameObject
    {
    public:
        CircleGameObject(const sf::Texture &texture, b2Body *body, float radius);
        CircleGameObject(const sf::Texture &texture, b2Body *body);
        ~CircleGameObject();

        virtual sf::Shape &getBodyShape() override;

    private:
        CircleGameObject();

        b2CircleShape shape;
        sf::CircleShape graphicalShape;
    };
}

#endif