#pragma once
#include <SFML/Graphics.hpp>
#include "math/Vector2D.hpp"
#include <cfloat>

constexpr size_t MAX_BUFFER_SIZE = 942;


class OrbitTrail {
    private:
        sf::Vertex trail[MAX_BUFFER_SIZE];
        size_t currentWriteIndex = 0;
        size_t validCount = 0;
        float minDistanceSq = 0.0001f;
        sf::Vector2f lastVertexPosition = {-FLT_MAX, -FLT_MAX};

    public:
        void setMinDistance(float minDistance);
        void addVertex(const Vector2D& position);
        void draw(sf::RenderTarget& target) const;
};