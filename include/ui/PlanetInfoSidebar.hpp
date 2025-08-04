#pragma once

#include "ui/UIElement.hpp"
#include "ui/Label.hpp"
#include "ui/Panel.hpp"
#include "core/SelectionManager.hpp"
#include <memory>


class PlanetInfoSidebar : public UIElement {
    public:
        PlanetInfoSidebar(const sf::Vector2f& position, const sf::Vector2f& size, const SelectionManager& selectionManager, const Body* sun);

        void update(sf::Time dt) override;
        void draw(sf::RenderTarget &target) const override;
    private:
        const SelectionManager &selectionManager;
        const Body* sun;
        Panel backgroundPanel;
        std::vector<std::unique_ptr<Label>> labels;

        void setupLabels();

        void updateOrbitalInfo(const Body *, double sunDistance, double orbitalVelocity);
        void updateGeneralInfo(const Body *);
        void updatePhysicalInfo(const Body *, double sunDistance, double orbitalVelocity);
        void updateEnergyInfo(const Body *);
};