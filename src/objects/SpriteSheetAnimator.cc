#include "SpriteSheetAnimator.h"

namespace o2dt
{

    SpriteSheetAnimator::SpriteSheetAnimator(float animationSpeed, sf::Sprite &spriteSheet,
                                             uint32_t frameWidth, uint32_t frameHeight,
                                             uint32_t gridSizeX, uint32_t gridSizeY) : spriteSheet(spriteSheet)
    {
        this->animationSpeed = animationSpeed;
        this->frameWidth = frameWidth;
        this->frameHeight = frameHeight;
        this->gridSizeX = gridSizeX;
        this->gridSizeY = gridSizeY;
        spriteSheet.setTextureRect(sf::IntRect(sf::Vector2i(0, 0),
                                               sf::Vector2i(frameWidth, frameHeight)));
    }

    void SpriteSheetAnimator::setAnimation(sf::Vector2i start, sf::Vector2i end)
    {
        if (start != startFrame) // This is a new animation request
        {
            startFrame = start;
            endFrame = end;
            currentFrame = startFrame;
            clock.restart();
        }
        else if (clock.getElapsedTime().asSeconds() >= animationSpeed) // Move the frame
        {
            if (currentFrame == endFrame)
            {
                currentFrame = startFrame;
            }
            else if (currentFrame.x + 1 < gridSizeX)
            {
                currentFrame.x++;
            }
            else
            {
                currentFrame.y++;
                currentFrame.x = 0;
            }
            clock.restart();
        }
        spriteSheet.setTextureRect(sf::IntRect(sf::Vector2i(currentFrame.x * frameWidth, currentFrame.y * frameHeight),
                                               sf::Vector2i(frameWidth, frameHeight)));
    }

    void SpriteSheetAnimator::setAnimationSpeed(float animationSpeed)
    {
        this->animationSpeed = animationSpeed;
    }
}