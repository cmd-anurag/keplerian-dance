#pragma once
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"

class InputHandler {
    public:
        InputHandler();
        void handleInputs(sf::RenderWindow& window, Camera& camera);

    private:
        bool isPanning;
        sf::Vector2i lastMousePosition;
};