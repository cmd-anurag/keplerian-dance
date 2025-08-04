#include <SFML/Graphics.hpp>
#include "math/Vector2D.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/QuoteManager.hpp"
#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "input/InputHandler.hpp"
#include "ui/UIManager.hpp"
#include "ui/Panel.hpp"
#include "ui/Label.hpp"
#include "ui/PlanetInfoSidebar.hpp"

enum class GameState { Loading, Running };

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "sim");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // --- State and Loading Screen Setup ---
    GameState currentState = GameState::Loading;
    QuoteManager quoteManager("../assets/quotes.txt");

    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/GrenzeGotisch-Regular.ttf")) {
        std::cerr << "Could not load font!\n";
        return 1;
    }

    sf::Text quoteText(quoteManager.getRandomQuote(), font, 32);
    quoteText.setFillColor(sf::Color::White);
    sf::FloatRect textRect = quoteText.getLocalBounds();
    quoteText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    quoteText.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 100));

    sf::Text startText("Press any key to start the Simulation.", font, 24);
    sf::FloatRect startTextRect = startText.getLocalBounds();
    startText.setOrigin(startTextRect.left + startTextRect.width / 2.f, startTextRect.top + startTextRect.height / 2.f);
    startText.setFillColor(sf::Color(200, 200, 200, 255));
    startText.setPosition(sf::Vector2f(window.getSize().x / 2.0f, 700.0f));

    sf::RectangleShape fadeOverlay(sf::Vector2f(window.getSize()));
    sf::Clock loadingClock;
    float fadeDuration = 2.5f;
    float delayBeforeFade = 1.0f;
    float totalLoadingTime = 7.0f;

    Simulation simulation;
    Camera camera;
    Renderer renderer(window);
    InputHandler inputHandler;
    UIManager uiManager;
    SelectionManager selectionManager;
    selectionManager.setSelected(&simulation.getBodies().at(3)); //  earth is selected by default

    const Body* sun = &simulation.getBodies().front();
    auto sidebar = std::make_unique<PlanetInfoSidebar>(sf::Vector2f(10.f, 10.f), sf::Vector2f(350.f, 1000.f), selectionManager, sun);
    uiManager.addElement(std::move(sidebar));

    
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("../assets/sprites/bg.png")) {
        std::cerr << "Unable to load the bg image\n";
        return 1;
    }
    sf::Sprite background(backgroundTexture);

    sf::Clock simulClock;

    while(window.isOpen())
    {
        sf::Time dt = simulClock.restart();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            switch (currentState)
            {
                case GameState::Loading:
                    // skipping the loading screen
                    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                        currentState = GameState::Running;
                    }
                    break;
                case GameState::Running:
                    uiManager.handleEvent(event, window);
                    inputHandler.handleEvent(event, window, camera, simulation.getBodies(), selectionManager);
                    break;
            }
        }
        switch (currentState)
        {
            case GameState::Loading:
                {
                    float elapsed = loadingClock.getElapsedTime().asSeconds();

                    float alpha;
                    if (elapsed < delayBeforeFade) {
                        alpha = 255.0f;
                    } else {
                        alpha = 255.0f * std::max(0.0f, 1.0f - ((elapsed - delayBeforeFade) / fadeDuration));
                    }
                    fadeOverlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));
                }
                break;
            case GameState::Running:
                simulation.update(Constants::TIMESTEP);
                uiManager.update(dt);
                break;
        }

        window.clear();
        switch (currentState)
        {
            case GameState::Loading:
                window.clear(sf::Color::Black);
                window.draw(quoteText);
                window.draw(startText);
                if(fadeOverlay.getFillColor().a > 0) {
                    window.draw(fadeOverlay);
                }
                break;
            case GameState::Running:
                window.setView(window.getDefaultView());
                window.draw(background);
                renderer.drawWorld(simulation.getBodies(), camera, selectionManager);
                renderer.drawUI(uiManager);
                break;
        }
        window.display();
    }

    return 0;
}