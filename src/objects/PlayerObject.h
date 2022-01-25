#ifndef O2DT_PLAYER_GAME_OBJECT
#define O2DT_PLAYER_GAME_OBJECT

#include "PolygonGameObject.h"
#include <vector>

namespace o2dt
{
    class PlayerObject : public virtual PolygonGameObject
    {
    public:
        PlayerObject(const sf::Texture &texture, b2Body *body);

        void updateInput(std::vector<std::string> inputs);

    protected:
        PlayerObject();
        bool inputContains(std::string inputName);
        std::vector<std::string> latestInputs;

        // Player Meta Attributes
        float walkSpeed = 200.0f;
    };
}

#endif
