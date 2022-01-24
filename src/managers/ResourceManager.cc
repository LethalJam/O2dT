#include "ResourceManager.h"
#include <filesystem>

namespace o2dt
{
    ResourceManager::ResourceManager()
    {
        defaultFont.loadFromFile("resources/fonts/ARIAL.ttf");
        errorTexture.loadFromFile("resources/textures/ohno.png");
        loadAllResources();
    }
    ResourceManager::~ResourceManager() {}

    const sf::Texture &ResourceManager::getTexture(std::string name)
    {
        auto it = textureBank.find(name);
        if (it != textureBank.end())
        {
            return it->second;
        }
        else
        {
            return errorTexture;
        }
    }
    const sf::Font &ResourceManager::getFont(std::string name)
    {
        auto it = fontBank.find(name);
        if (it != fontBank.end())
        {
            return it->second;
        }
        else
        {
            return defaultFont;
        }
    }

    void ResourceManager::loadAllResources()
    {
        const std::filesystem::path texturePath("resources\\textures");
        for (auto const &dir_entry : std::filesystem::directory_iterator{texturePath})
        {
            std::string filename = dir_entry.path().filename().string();
            std::string path = dir_entry.path().relative_path().string();
            sf::Texture tex;
            tex.loadFromFile(path);
            textureBank.insert(std::pair<std::string, sf::Texture>(filename, tex));
        }

        const std::filesystem::path fontPath("resources\\fonts");
        for (auto const &dir_entry : std::filesystem::directory_iterator{fontPath})
        {
            std::string filename = dir_entry.path().filename().string();
            std::string path = dir_entry.path().relative_path().string();
            sf::Font font;
            font.loadFromFile(path);
            fontBank.insert(std::pair<std::string, sf::Font>(filename, font));
        }
    }
}