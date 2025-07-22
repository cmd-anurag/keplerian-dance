#pragma once
#include "math/Vector2D.hpp"

class Camera {
    public:
        Camera();

        void setCenter(const Vector2D& position);
        Vector2D getCenter() const;

        void setZoom(float zoom);
        float getZoom() const;

        void setScale(float scale);
        float getScale() const;

        void move(const Vector2D& offset);

    private:
        float zoom; 
        float scale; // no. of pixels in a single world unit.
        Vector2D center;
};

