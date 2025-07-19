#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "graphics/Camera.hpp"
#include "core/Body.hpp"

class Renderer {
    public:
        Renderer(sf::RenderWindow &window, const Camera &camera);
        void draw(const std::vector<Body> &bodies);

    private:
        sf::RenderWindow &window;
        const Camera &camera;

        sf::Vector2f worldToScreen(const Vector2D& worldPosition);
};