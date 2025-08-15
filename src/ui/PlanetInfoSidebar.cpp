#include "ui/PlanetInfoSidebar.hpp"
#include "core/Body.hpp"
#include "utils/Format.hpp"

PlanetInfoSidebar::PlanetInfoSidebar(const sf::Vector2f &position, const sf::Vector2f &size, const SelectionManager &selectionManager, const Body* sun) : selectionManager(selectionManager), backgroundPanel(position, size), sun(sun) {
    setupLabels();
}

void PlanetInfoSidebar::update(sf::Time dt)
{
    if(selectionManager.hasSelection())
    {
        Body* selectedBody = selectionManager.getSelected();
        double v = selectedBody->velocity.magnitude();
        double sunDistance = (selectedBody->position - sun->position).magnitude();
        sunDistance = std::max(0.00001, sunDistance);

        updateGeneralInfo(selectedBody);
        updateOrbitalInfo(selectedBody, sunDistance, v);
        updatePhysicalInfo(selectedBody, sunDistance, v);
        updateEnergyInfo(selectedBody);
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

void PlanetInfoSidebar::updateOrbitalInfo(const Body *selectedBody, double sunDistance, double orbitalVelocity)
{
        labels[2]->setText("Position: " + std::to_string(selectedBody->position.x) + " AU, " + std::to_string(selectedBody->position.y) + " AU");
        labels[3]->setText("Distance from the Sun: " + Format::toRealDistance(sunDistance));
        labels[4]->setText("Orbital Speed: " + Format::toRealVelocity(orbitalVelocity));
        labels[5]->setText("Orbital Period: " + Format::toRealTime(selectedBody->calculateOrbitalPeriod(*sun)));
        labels[6]->setText("Orbital Phase: " + std::to_string(selectedBody->phaseAngle) + " deg");
        labels[7]->setText("Orbits Completed: " + std::to_string(selectedBody->orbitsCompleted));
        labels[8]->setText("Orbital Eccentricity: " + std::to_string(selectedBody->eccentricity));
        labels[9]->setText("Angular Momentum: " + std::to_string(selectedBody->angularMomentum(*sun)));
}

void PlanetInfoSidebar::updateGeneralInfo(const Body *selectedBody)
{
    labels[0]->setText(selectedBody->name);
    labels[1]->setText(selectedBody->description);
    labels[20]->setText("No. of Moons: " + std::to_string(selectedBody->moonCount));
    labels[21]->setText("Nicknames: " + selectedBody->nicknames);
}

void PlanetInfoSidebar::updatePhysicalInfo(const Body *selectedBody, double sunDistance, double orbitalVelocity)
{
    labels[10]->setText("Acceleration: " + Format::toRealAcceleration(selectedBody->acceleration.magnitude()));
    labels[11]->setText("Centripetal Force: " + std::to_string((selectedBody->mass * orbitalVelocity * orbitalVelocity) / sunDistance));

    labels[12]->setText("Mass: " + Format::toRealMass(selectedBody->mass));
    labels[13]->setText("Surface Temperature: " + std::to_string(selectedBody->surfaceTemperature) + " celsius");
    labels[14]->setText("Rotational Period: " + std::to_string(selectedBody->rotationalPeriod) + " earth hours");
    labels[15]->setText("Gravity at Surface: " + std::to_string(selectedBody->calculateGravityAtSurface()));
    labels[16]->setText("Escape Velocity: " + Format::toRealVelocity(selectedBody->calculateEscapeVelocity()));
}

void PlanetInfoSidebar::updateEnergyInfo(const Body *selectedBody)
{
    double ke = selectedBody->kineticEnergy();
    double pe = selectedBody->potentialEnergy(*sun);
    double te = ke + pe;
    labels[17]->setText("Kinetic Energy: " + std::to_string(ke));
    labels[18]->setText("Potential Energy: " + std::to_string(pe));
    labels[19]->setText("Total Energy: " + std::to_string(te));
}