#ifndef O2DT_SPRITE_SHEET_ANIMATOR
#define O2DT_SPRITE_SHEET_ANIMATOR

#include <SFML/Graphics.hpp>
#include <map>

namespace o2dt
{

    class SpriteSheetAnimator
    {
    public:
        SpriteSheetAnimator(float animationSpeed, sf::Sprite &spriteSheet,
                            uint32_t frameWidth, uint32_t frameHeight,
                            uint32_t gridSizeX, uint32_t gridSizeY);

        void setAnimation(sf::Vector2i start, sf::Vector2i end);
        void setAnimationSpeed(float animationSpeed);

    private:
        sf::Sprite &spriteSheet;
        sf::Clock clock;

        float animationSpeed; // Lower is faster
        uint32_t frameWidth;
        uint32_t frameHeight;
        uint32_t gridSizeX;
        uint32_t gridSizeY;

        sf::Vector2i startFrame;
        sf::Vector2i endFrame;
        sf::Vector2i currentFrame;
    };
}

#endif