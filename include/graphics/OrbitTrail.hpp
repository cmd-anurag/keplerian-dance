#pragma once
#include <SFML/Graphics.hpp>
#include "math/Vector2D.hpp"

constexpr size_t MAX_BUFFER_SIZE = 2000;


class OrbitTrail {
    private:
        sf::Vertex trail[MAX_BUFFER_SIZE];
        size_t currentWriteIndex = 0;
        size_t validCount = 0;

    public:
        void addVertex(const Vector2D& position);
        void draw(sf::RenderTarget& target) const;
};