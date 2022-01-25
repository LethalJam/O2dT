#ifndef O2DT_GAME_LOOP_H
#define O2DT_GAME_LOOP_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../managers/ResourceManager.h"
#include "../managers/InputManager.h"
#include "../objects/GameWorld.h"

namespace o2dt
{
    class GameLoop
    {
    public:
        GameLoop();
        ~GameLoop();
        void start();

    private:
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<o2dt::ResourceManager> resourceManager;
        std::unique_ptr<o2dt::InputManager> inputManager;
        std::unique_ptr<o2dt::GameWorld> gameWorld;

        sf::Vector2u defaultSize = sf::Vector2u(1600, 900);
        std::string title = "O2dT";
    };

}

#endif