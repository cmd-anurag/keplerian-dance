#pragma once

#include <memory>
#include <vector>
#include "ui/UIElement.hpp"

class UIManager {
    public:
        void addElement(std::unique_ptr<UIElement> element);
        void handleEvent(const sf::Event &event, const sf::RenderWindow &window);

        void update(sf::Time dt);
        void draw(sf::RenderTarget &target) const;
    private:
        std::vector<std::unique_ptr<UIElement>> elements;
};