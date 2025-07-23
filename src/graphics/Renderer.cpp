#include "graphics/Renderer.hpp"
#include "core/Constants.hpp"

Renderer::Renderer(sf::RenderWindow &window) : window(window) {};

void Renderer::draw(const std::vector<Body> &bodies, Camera &camera)
{
    float pixelsPerWorldUnit = camera.getScale() * camera.getZoom();

    view.setCenter(camera.getCenter().toSFMLVector());
    view.setSize(
        static_cast<float>(window.getSize().x) / pixelsPerWorldUnit,
        static_cast<float>(window.getSize().y) / pixelsPerWorldUnit
    );
    window.setView(view);

    window.clear();
    for(const auto &body : bodies)
    {
        sf::CircleShape shape(body.radius);
        shape.setOrigin(body.radius, body.radius);
        shape.setPosition(body.position.x, body.position.y);

        if(body.texture) {
            shape.setTexture(body.texture);
        }
        else {
            shape.setFillColor(sf::Color::Magenta); // missing textures
        }

        window.draw(body.getTrail());
        window.draw(shape);
    }

    window.setView(window.getDefaultView());
    window.display();
}