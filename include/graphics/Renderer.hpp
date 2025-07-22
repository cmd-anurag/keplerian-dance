#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"
#include "core/Body.hpp"

class Renderer {
    public:
        Renderer(sf::RenderWindow &window);
        void draw(const std::vector<Body> &bodies, Camera &camera);

    private:
        sf::RenderWindow &window;
        sf::View view;
};