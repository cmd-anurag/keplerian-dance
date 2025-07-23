#include "graphics/OrbitTrail.hpp"

void OrbitTrail::addVertex(const Vector2D &position)
{
    sf::Vertex vertex(position.toSFMLVector());
    trail[currentWriteIndex++] = vertex;
    validCount = std::min(validCount + 1, MAX_BUFFER_SIZE);
    if(currentWriteIndex >= MAX_BUFFER_SIZE) currentWriteIndex = 0;
}

void OrbitTrail::draw(sf::RenderTarget &target) const
{
    if(validCount <= 1) return;

    if(validCount < MAX_BUFFER_SIZE)
    {
        // Situation 1 - the buffer is not yet full
        target.draw(trail, validCount, sf::LineStrip);
    }
    else {
        // part 1 - draw from oldest to end , oldest would be where the write index is.
        target.draw(trail + currentWriteIndex, MAX_BUFFER_SIZE - currentWriteIndex, sf::LineStrip);
        
        // part 2 - draw from start to newest
        target.draw(trail, currentWriteIndex - 1, sf::LineStrip);
    }
}