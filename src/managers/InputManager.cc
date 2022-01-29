#include "InputManager.h"

namespace o2dt
{
    InputManager::InputManager()
    {
        // Set Default Keys
        inGameKeyMapping = {{"moveLeft", sf::Keyboard::A},
                            {"moveRight", sf::Keyboard::D},
                            {"moveUp", sf::Keyboard::W},
                            {"moveDown", sf::Keyboard::S},
                            {"sprint", sf::Keyboard::LShift},
                            {"sneak", sf::Keyboard::LControl}};
    }
    InputManager::~InputManager() {}

    void InputManager::setKeyMapping(std::string keyName, sf::Keyboard::Key key, InputContext context)
    {
        switch (context)
        {
        case InputContext::IN_GAME:
        {
            auto keyIt = inGameKeyMapping.find(keyName);
            if (keyIt != inGameKeyMapping.end())
            {
                keyIt->second = key;
            }
            else
            {
                // TODO: Handle Error
            }
            break;
        }

        default:
            break;
        }
    }

    std::vector<std::string> InputManager::getInputData(InputContext context)
    {
        std::vector<std::string> inputs;
        for (auto it = inGameKeyMapping.begin(); it != inGameKeyMapping.end(); ++it)
        {
            if (sf::Keyboard::isKeyPressed(it->second))
            {
                inputs.push_back(it->first);
            }
        }
        return inputs;
    }
}