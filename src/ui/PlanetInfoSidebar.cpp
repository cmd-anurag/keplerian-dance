#include "ui/PlanetInfoSidebar.hpp"
#include "core/Body.hpp"

PlanetInfoSidebar::PlanetInfoSidebar(const sf::Vector2f &position, const sf::Vector2f &size, const SelectionManager &selectionManager, const Body* sun) : selectionManager(selectionManager), backgroundPanel(position, size), sun(sun) {
    setupLabels();
}

void PlanetInfoSidebar::update(sf::Time dt)
{
    if(selectionManager.hasSelection())
    {
        Body* selectedBody = selectionManager.getSelected();
        labels[0]->setText(selectedBody->name);
        labels[1]->setText("Mass: " + std::to_string(selectedBody->mass));
        labels[2]->setText("Velocity: " + std::to_string(selectedBody->velocity.magnitude()));
        labels[3]->setText("Position: " + std::to_string(selectedBody->position.x) + ", " + std::to_string(selectedBody->position.y));
        labels[4]->setText("Distance from the Sun: " + std::to_string((selectedBody->position - sun->position).magnitude()));
    }
}

void PlanetInfoSidebar::draw(sf::RenderTarget &target) const
{
    if(selectionManager.hasSelection()){
        backgroundPanel.draw(target);
        for(const auto& label : labels)
        {
            label->draw(target);
        }
    }
}

void PlanetInfoSidebar::setupLabels() 
{
    sf::Vector2f panelPosition = backgroundPanel.getPosition();
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 15, panelPosition.y + 20), "", 48));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 100), "Mass: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 135), "Velocity: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 170), "Position: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 205), "Distance From Sun: ", 16));

};