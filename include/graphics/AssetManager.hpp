#pragma once
#include <SFML/Graphics.hpp>
#include<string>
#include<map>

class AssetManager {
    public:
        sf::Texture& getTexture(const std::string& filename);
    private:
        std::map<std::string, sf::Texture> textures;
};