#include "input/InputHandler.hpp"

void InputHandler::handleInputs(sf::RenderWindow &window, Camera &camera)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) window.close();
        
        if(event.type == sf::Event::MouseWheelScrolled) {
            if(event.mouseWheelScroll.delta > 0) {
                camera.setZoom(camera.getZoom() * 1.05f);
            } 
            else {
                camera.setZoom(camera.getZoom() * 0.95f);
            }
        }
    }
}
