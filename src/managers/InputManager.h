#ifndef O2DT_INPUT_MANAGER
#define O2DT_INPUT_MANAGER

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

namespace o2dt
{
    enum InputContext
    {
        MENU,
        IN_GAME,
        INVENTORY
    };
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();

        void setKeyMapping(std::string keyName, sf::Keyboard::Key key, InputContext context);
        std::vector<std::string> getInputData(InputContext context);

    private:
        std::map<std::string, sf::Keyboard::Key> inGameKeyMapping;
    };
}

#endif