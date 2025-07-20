#pragma once
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"

class InputHandler {
    public:
        void handleInputs(sf::RenderWindow& window, Camera& camera);
};