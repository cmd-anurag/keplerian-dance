#include "graphics/AssetManager.hpp"
#include <iostream>

sf::Texture &AssetManager::getTexture(const std::string &filename)
{
    if(textures.find(filename) == textures.end())
    {
        if(!textures[filename].loadFromFile(filename))
        {
            std::cerr << "AssetManager::getTexture() failed to load the asset " << filename << std::endl;
        }
    }

    return textures[filename];
}