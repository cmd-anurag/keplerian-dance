#pragma once
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"
#include "core/Body.hpp"
#include "core/SelectionManager.hpp"

class InputHandler {
    public:
        InputHandler();
        void handleEvent(const sf::Event &event, sf::RenderWindow& window, Camera& camera, std::vector<Body> &bodies, SelectionManager &selectionManager);

    private:
        bool isPanning;
        sf::Vector2i lastMousePosition;
};