#include "input/InputHandler.hpp"


InputHandler::InputHandler()
{
    isPanning = false;
}


void InputHandler::handleEvent(const sf::Event &event, sf::RenderWindow &window, Camera &camera, std::vector<Body> &bodies, SelectionManager &selectionManager)
{
    // 1. Mouse Scroll Event

    if(event.type == sf::Event::MouseWheelScrolled) {
        if(event.mouseWheelScroll.delta > 0) {
            camera.setZoom(camera.getZoom() * 1.05f);
        } 
        else {
            camera.setZoom(camera.getZoom() * 0.95f);
        }
    }

    // 2. Pan Event

    // mouse left is pressed
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
    {
        isPanning = true;
        lastMousePosition = sf::Mouse::getPosition(window);
    }

    // mouse left is released
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
    {
        isPanning = false;
    }

    // mouse moved while panning
    if(isPanning && event.type == sf::Event::MouseMoved)
    {
        sf::Vector2i mouseDelta = sf::Mouse::getPosition(window) - lastMousePosition;

        float conversionFactor = camera.getScale() * camera.getZoom();

        camera.move({
            -static_cast<float>(mouseDelta.x) / conversionFactor,
            -static_cast<float>(mouseDelta.y) / conversionFactor
        });

        lastMousePosition = sf::Mouse::getPosition(window);
    }

    // ----------------- CLICK ON PLANET ---------------------- //
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        sf::View currentView;
        float pixelsPerWorldUnit = camera.getScale() * camera.getZoom();
        currentView.setCenter(camera.getCenter().toSFMLVector());
        currentView.setSize(
            static_cast<float>(window.getSize().x) / pixelsPerWorldUnit,
            static_cast<float>(window.getSize().y) / pixelsPerWorldUnit
        );

        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos, currentView);
        
        for(auto &body : bodies)
        {
            double dx = body.position.x - worldPos.x;
            double dy = body.position.y - worldPos.y;
            if(dx * dx + dy * dy < body.radius * body.radius)
            {
                selectionManager.setSelected(&body);
                // looks ugly, maybe if i implement lerping
                // camera.setCenter(body.position);
                // camera.setZoom(3);
                break;
            }
            else
            {
                selectionManager.clearSelection();
            }
        }
    }
}
