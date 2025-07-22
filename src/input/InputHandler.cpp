#include "input/InputHandler.hpp"

InputHandler::InputHandler()
{
    isPanning = false;
}


void InputHandler::handleInputs(sf::RenderWindow &window, Camera &camera)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        // 1. Close event

        if(event.type == sf::Event::Closed) window.close();

        // 2. Mouse Scroll Event

        if(event.type == sf::Event::MouseWheelScrolled) {
            if(event.mouseWheelScroll.delta > 0) {
                camera.setZoom(camera.getZoom() * 1.05f);
            } 
            else {
                camera.setZoom(camera.getZoom() * 0.95f);
            }
        }

        // 3. Pan Event

        // mouse left is pressed
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            isPanning = true;
            lastMousePosition = sf::Mouse::getPosition(window);
        }

        // mouse left is released
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
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
    }
}
