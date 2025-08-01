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

        double v = selectedBody->velocity.magnitude();
        double sunDistance = (selectedBody->position - sun->position).magnitude();
        sunDistance = std::max(0.00001, sunDistance);

        labels[0]->setText(selectedBody->name);
        labels[1]->setText(selectedBody->description);

        labels[2]->setText("Position: " + std::to_string(selectedBody->position.x) + ", " + std::to_string(selectedBody->position.y));
        labels[3]->setText("Distance from the Sun: " + std::to_string(sunDistance));
        labels[4]->setText("Orbital Speed: " + std::to_string(v));
        labels[5]->setText("Orbital Period: " + std::to_string(selectedBody->calculateOrbitalPeriod(*sun)));
        labels[6]->setText("Orbital Phase: " + std::to_string(selectedBody->phaseAngle));
        labels[7]->setText("Orbits Completed: " + std::to_string(selectedBody->orbitsCompleted));
        labels[8]->setText("Orbital Eccentricity: " + std::to_string(selectedBody->eccentricity));
        labels[9]->setText("Angular Momentum: " + std::to_string(selectedBody->angularMomentum(*sun)));

        labels[10]->setText("Acceleration: " + std::to_string(selectedBody->acceleration.magnitude()));
        labels[11]->setText("Centripetal Force: " + std::to_string((selectedBody->mass * v * v) / sunDistance));

        labels[12]->setText("Mass: " + std::to_string(selectedBody->mass));
        labels[13]->setText("Surface Temperature: " + std::to_string(selectedBody->surfaceTemperature));
        labels[14]->setText("Rotational Period: " + std::to_string(selectedBody->rotationalPeriod) + " earth hours");
        labels[15]->setText("Gravity at Surface: " + std::to_string(selectedBody->calculateGravityAtSurface()));
        labels[16]->setText("Escape Velocity: " + std::to_string(selectedBody->calculateEscapeVelocity()));

        labels[17]->setText("Kinetic Energy: " + std::to_string(ke));
        labels[18]->setText("Potential Energy: " + std::to_string(pe));
        labels[19]->setText("Total Energy: " + std::to_string(te));

        labels[20]->setText("No. of Moons: " + std::to_string(selectedBody->moonCount));
        labels[21]->setText("Nicknames: " + selectedBody->nicknames);
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


    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 230), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 265), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 300), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 335), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 370), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 405), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 440), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 475), "", 18));

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 530), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 565), "", 18));

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 620), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 655), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 690), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 725), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 760), "", 18));

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 815), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 850), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 885), "", 18));

    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 940), "", 18));
    labels.push_back(std::make_unique<Label>(sf::Vector2f(panelPosition.x + 25, panelPosition.y + 975), "", 18));
};