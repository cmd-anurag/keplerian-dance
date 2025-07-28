#pragma once

#include "ui/UIElement.hpp"

class Panel : public UIElement {
    public:
        Panel(const sf::Vector2f &position, const sf::Vector2f &size);
        void setColor(const sf::Color &color);
        void draw(sf::RenderTarget &target) const override;
        sf::Vector2f getPosition() const;

    private:
        sf::RectangleShape rectangleShape;
};