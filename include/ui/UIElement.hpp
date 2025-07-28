// this is the base abstract class for all UI elements

#pragma once
#include<SFML/Graphics.hpp>

class UIElement {
    public:
        virtual ~UIElement() = default;

        virtual void handleEvent(const sf::Event &event, const sf::RenderWindow &window) {};
        virtual void update(sf::Time dt) {};
        virtual void draw(sf::RenderTarget &window) const = 0;
};