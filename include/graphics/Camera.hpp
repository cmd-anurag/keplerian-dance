#pragma once
#include "math/Vector2D.hpp"

class Camera {
    public:
        Camera();

        void setCenter(const Vector2D& position);
        Vector2D getCenter() const;

        void setZoom(float zoom);
        float getZoom() const;

    private:
        float zoom;
        Vector2D center;
};

