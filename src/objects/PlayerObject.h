#ifndef O2DT_PLAYER_GAME_OBJECT
#define O2DT_PLAYER_GAME_OBJECT

#include "PolygonGameObject.h"
#include "SpriteSheetAnimator.h"
#include <vector>

namespace o2dt
{
    enum MovementState
    {
        IDLE,
        WALKING,
        SPRINTING,
        SNEAKING
    };
    enum PlayerState
    {
        ALIVE,
        DEAD
    };
    class PlayerObject : public virtual PolygonGameObject
    {
    public:
        PlayerObject(const sf::Texture &texture, b2Body *body);

        void updateInput(std::vector<std::string> inputs);
        const MovementState &getMovementState();
        const PlayerState &getPlayerState();

    protected:
        PlayerObject();
        bool inputContains(std::string inputName);
        void animate(b2Vec2 &vel);

        std::vector<std::string> latestInputs;

        // Player Meta Attributes
        float walkSpeed = 100.0f;
        float sprintModifier = 2.0f;
        float animationSpeed = 0.15f;

        // Mechanics
        MovementState pMovState = MovementState::IDLE;
        MovementState pMovStatePrev = MovementState::IDLE;
        PlayerState pState = PlayerState::ALIVE;

        o2dt::SpriteSheetAnimator animator;
    };
}

#endif