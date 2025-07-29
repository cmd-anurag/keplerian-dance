#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"
#include "core/Body.hpp"
#include "core/SelectionManager.hpp"
#include "ui/UIManager.hpp"

class Renderer {
    public:
        Renderer(sf::RenderWindow &window);
        void drawWorld(const std::vector<Body> &bodies, Camera &camera, SelectionManager& selectionManager);
        void drawUI(const UIManager& uiManager);

    private:
        sf::RenderWindow &window;
        sf::View view;
};