#include "graphics/Renderer.hpp"
#include "core/Constants.hpp"

Renderer::Renderer(sf::RenderWindow &window, const Camera &camera) : window(window), camera(camera) {};

void Renderer::draw(const std::vector<Body> &bodies)
{
    window.clear();
    
    float pixelsPerWorldUnit = camera.getZoom();

    for(const auto &body : bodies)
    {
        float visualRadius = body.radius * pixelsPerWorldUnit;
        visualRadius = std::max(2.0f, visualRadius);
        sf::Vector2f screemPosition = worldToScreen(body.position);

        sf::CircleShape shape(visualRadius);
        shape.setOrigin(visualRadius, visualRadius);
        shape.setFillColor(body.color);
        shape.setPosition(screemPosition);

        window.draw(shape);
    }
    window.display();
}

sf::Vector2f Renderer::worldToScreen(const Vector2D &worldPosition)
{
    float pixelsPerWorldUnit = camera.getZoom();

    float screenX = worldPosition.x * pixelsPerWorldUnit;
    float screenY = worldPosition.y * pixelsPerWorldUnit;

    screenX += window.getSize().x / 2.0f;
    screenY += window.getSize().y / 2.0f;

    return sf::Vector2f(screenX, screenY);
}