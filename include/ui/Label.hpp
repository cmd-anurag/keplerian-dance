#pragma once
#include "ui/UIElement.hpp"

class Label : public UIElement {
    private:
        sf::Font font;
        sf::Text text;

    public:
        Label(const sf::Vector2f &position, const std::string &content, unsigned int characterSize = 32, const std::string &fontname = "SpaceMono-Regular.ttf");
        void setText(const std::string& content);
        void setCharacterSize(unsigned int charSize);
        void setColor(sf::Color &color);

        void draw(sf::RenderTarget &target) const;
};