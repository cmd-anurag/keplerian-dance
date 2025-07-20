#include <SFML/Graphics.hpp>
#include "math/Vector2D.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Renderer.hpp"
#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "input/InputHandler.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "sim");
    window.setFramerateLimit(60);

    Simulation simulation;
    Camera camera;
    Renderer renderer(window, camera);
    InputHandler inputHandler;

    // TODO - rather than using a total scratch implementation of Camera, use sf::View and refactor the codebase

    while(window.isOpen())
    {
        inputHandler.handleInputs(window, camera);

        simulation.update(Constants::TIMESTEP);
        renderer.draw(simulation.getBodies());
    }

    return 0;
}