#include "ui/Panel.hpp"

Panel::Panel(const sf::Vector2f &position, const sf::Vector2f &size)
{
    rectangleShape.setPosition(position);
    rectangleShape.setSize(size);
    rectangleShape.setFillColor(sf::Color(0, 0, 0, 0));
    rectangleShape.setOutlineThickness(1);
    rectangleShape.setOutlineColor(sf::Color::White);
}

void Panel::setColor(const sf::Color &color)
{
    rectangleShape.setFillColor(color);
}

void Panel::draw(sf::RenderTarget &target) const
{
    target.draw(rectangleShape);
}

sf::Vector2f Panel::getPosition() const {
    return rectangleShape.getPosition();
}
