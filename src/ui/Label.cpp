#include "ui/Label.hpp"
#include <iostream>

Label::Label(const sf::Vector2f &position, const std::string &content, unsigned int characterSize)
{
    if(!font.loadFromFile("../assets/fonts/Gugi-Regular.ttf"))
    {
        std::cerr << "Unable to load font for label" << std::endl;
    }

    text.setFont(font);
    text.setPosition(position);
    text.setString(content);
    text.setCharacterSize(characterSize);
    text.setFillColor(sf::Color::White);
}

void Label::setText(const std::string& content) {
    text.setString(content);
}

void Label::setCharacterSize(unsigned int charSize) {
    text.setCharacterSize(charSize);
}

void Label::setColor(sf::Color &color) {
    text.setFillColor(color);
}

void Label::draw(sf::RenderTarget &target) const {
    target.draw(text);
}