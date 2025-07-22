#include "graphics/Camera.hpp"

Camera::Camera()
{
    center = Vector2D(0.0f, 0.0f);
    zoom = 1.0f;
    scale = 100.0f;
}

void Camera::setCenter(const Vector2D &position)
{
    center = position;
}

Vector2D Camera::getCenter() const
{
    return center;
}

void Camera::setZoom(float zoom)
{
    this->zoom = zoom;
}

float Camera::getZoom() const
{

    return this->zoom;
}

void Camera::setScale(float scale)
{
    this->scale = scale;
}

float Camera::getScale() const {
    return scale;
}

void Camera::move(const Vector2D& offset)
{
    center += offset;
}