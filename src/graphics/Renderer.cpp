#include "graphics/Renderer.hpp"
#include "core/Constants.hpp"

Renderer::Renderer(sf::RenderWindow &window) : window(window) {};

void Renderer::drawWorld(const std::vector<Body> &bodies, Camera &camera, SelectionManager& selectionManager)
{
    float pixelsPerWorldUnit = camera.getScale() * camera.getZoom();

    view.setCenter(camera.getCenter().toSFMLVector());
    view.setSize(
        static_cast<float>(window.getSize().x) / pixelsPerWorldUnit,
        static_cast<float>(window.getSize().y) / pixelsPerWorldUnit
    );
    window.setView(view);
    
    if(selectionManager.hasSelection())
    {
        Body* selectedBody = selectionManager.getSelected();
        selectedBody->getTrail().draw(window);
    }

    for(const auto &body : bodies)
    {
        // body.getTrail().draw(window);
        // view culling only for planets
        if(!body.isInView(view)) continue;

        sf::CircleShape shape(body.visualRadius);
        shape.setOrigin(body.visualRadius, body.visualRadius);
        shape.setPosition(body.position.x, body.position.y);

        if(body.texture) {
            shape.setTexture(body.texture);
        }
        else {
            shape.setFillColor(sf::Color::Magenta); // missing textures
        }
        window.draw(shape);
    }

    window.setView(window.getDefaultView());

}
void Renderer::drawUI(const UIManager &uiManager)
{
    window.setView(window.getDefaultView());
    uiManager.draw(window);
}