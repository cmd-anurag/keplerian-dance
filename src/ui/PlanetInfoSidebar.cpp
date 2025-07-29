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
        labels[1]->setText(selectedBody->description);
        labels[2]->setText("Mass: " + std::to_string(selectedBody->mass));
        labels[3]->setText("Velocity: " + std::to_string(selectedBody->velocity.magnitude()));
        labels[4]->setText("Position: " + std::to_string(selectedBody->position.x) + ", " + std::to_string(selectedBody->position.y));
        labels[5]->setText("Distance from the Sun: " + std::to_string((selectedBody->position - sun->position).magnitude()));
        labels[6]->setText("Kinetic Energy: " + std::to_string(ke));
        labels[7]->setText("Potential Energy: " + std::to_string(pe));
        labels[8]->setText("Total Energy: " + std::to_string(te));
        labels[9]->setText("Angular Momentum: " + std::to_string(selectedBody->angularMomentum(*sun)));
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
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 20), "", 56, "Gugi-Regular.ttf"));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 100), "", 20, "ChakraPetch-Regular.ttf"));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 230), "Mass: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 265), "Velocity: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 300), "Position: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 335), "Distance From Sun: ", 18));

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 390), "Kinetic Energy: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 425), "Potential Energy: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 460), "Total Energy: ", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 495), "Angular Momentum: ", 18));
};