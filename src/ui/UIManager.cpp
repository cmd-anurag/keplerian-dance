#include "ui/UIManager.hpp"

void UIManager::addElement(std::unique_ptr<UIElement> element) {
    elements.push_back(std::move(element));
}

void UIManager::handleEvent(const sf::Event &event, const sf::RenderWindow &window) {
    for(const auto& element : elements)
    {
        element->handleEvent(event, window);
    }
}

void UIManager::update(sf::Time dt) {
    for(const auto& element : elements)
    {
        element->update(dt);
    }
}

void UIManager::draw(sf::RenderTarget &target) const {
    for(const auto& element : elements)
    {
        element->draw(target);
    }
}