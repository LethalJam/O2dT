#ifndef O2DT_POLYGON_GAME_OBJECT
#define O2DT_POLYGON_GAME_OBJECT

#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include "GameObject.h"

namespace o2dt
{
    class PolygonGameObject : public virtual GameObject
    {
    public:
        PolygonGameObject(const sf::Texture &texture, b2Body *body, float width, float height);
        PolygonGameObject(const sf::Texture &texture, b2Body *body);

        virtual sf::Shape &getBodyShape() override;

    protected:
        PolygonGameObject();

        bool isBox = false;
        b2PolygonShape shape;
        sf::ConvexShape graphicalShape;
    };
}

#endif