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
        double ke = selectedBody->kineticEnergy();
        double pe = selectedBody->potentialEnergy(*sun);
        double te = ke + pe;

        labels[0]->setText(selectedBody->name);
        labels[1]->setText("Mass: " + std::to_string(selectedBody->mass));
        labels[2]->setText("Velocity: " + std::to_string(selectedBody->velocity.magnitude()));
        labels[3]->setText("Position: " + std::to_string(selectedBody->position.x) + ", " + std::to_string(selectedBody->position.y));
        labels[4]->setText("Distance from the Sun: " + std::to_string((selectedBody->position - sun->position).magnitude()));
        labels[5]->setText("Kinetic Energy: " + std::to_string(ke));
        labels[6]->setText("Potentian Energy: " + std::to_string(pe));
        labels[7]->setText("Total Energy: " + std::to_string(te));
        labels[8]->setText("Angular Momentum: " + std::to_string(selectedBody->angularMomentum(*sun)));
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

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 275), "Kinetic Energy: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 310), "Potential Energy: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 345), "Total Energy: ", 16));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 20, panelPosition.y + 380), "Angular Momentum: ", 16));
};