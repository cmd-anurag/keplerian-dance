#include <SFML/Graphics.hpp>
#include "math/Vector2D.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Renderer.hpp"
#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "input/InputHandler.hpp"
#include "ui/UIManager.hpp"
#include "ui/Panel.hpp"
#include "ui/Label.hpp"
#include "ui/PlanetInfoSidebar.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "sim");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    Simulation simulation;
    Camera camera;
    Renderer renderer(window);
    InputHandler inputHandler;
    UIManager uiManager;
    SelectionManager selectionManager;

    const Body* sun = &simulation.getBodies().front();

    auto sidebar = std::make_unique<PlanetInfoSidebar>(sf::Vector2f(10.f, 10.f), sf::Vector2f(350.f, 1000.f), selectionManager, sun);
    uiManager.addElement(std::move(sidebar));

    // Background Image
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("../assets/sprites/bg.png"))
    {
        std::cerr << "Unable to load the bg image\n";
        return 1;
    }
    sf::Sprite background(backgroundTexture);
    
    sf::Clock simulClock;
    
    while(window.isOpen())
    {
        window.clear();
        window.setView(window.getDefaultView());
        window.draw(background);
        sf::Time dt = simulClock.restart();
        
        sf::Event event;
        while(window.pollEvent(event))
        {
            uiManager.handleEvent(event, window);
            inputHandler.handleEvent(event, window, camera, simulation.getBodies(), selectionManager);
            
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        
        simulation.update(Constants::TIMESTEP);
        uiManager.update(dt);
        
        
        renderer.drawWorld(simulation.getBodies(), camera, selectionManager);
        renderer.drawUI(uiManager);

        window.display();
    }

    return 0;
}