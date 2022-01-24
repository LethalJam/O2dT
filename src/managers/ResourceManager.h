#ifndef O2DT_RESOURCE_MANAGER
#define O2DT_RESOURCE_MANAGER

#include <map>
#include <SFML/Graphics.hpp>

namespace o2dt
{
    class ResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();

        const sf::Texture &getTexture(std::string name);
        const sf::Font &getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> textureBank;
        std::map<std::string, sf::Font> fontBank;
        sf::Texture errorTexture;
        sf::Font defaultFont;

        void loadAllResources();
    };
}

#endif