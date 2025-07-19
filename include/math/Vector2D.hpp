#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector2D {
        public:
            double x,y;

            Vector2D() : x(0), y(0) {};
            Vector2D(int x, int y) : x(x), y(y) {};
            Vector2D(double x , double y) : x(x), y(y) {};

            static Vector2D getZeroVector() {
                return Vector2D(0,0);
            }

            static double getSquaredDistanceBetween(Vector2D vec1, Vector2D vec2) {
                return (vec1.x - vec2.x) * (vec1.x - vec2.x) + (vec1.y - vec2.y) * (vec1.y - vec2.y);
            }

            double magnitude() const
            {
                return std::sqrt(x*x + y*y);
            }

            double magnitudeSquared() const
            {
                return x*x + y*y;
            }

            Vector2D normalized() const {
                double length = magnitude();
                if(length == 0) return {0,0};
                return {x/length, y/length};
            }

            void normalize() {
                double length = magnitude();
                if(length != 0)
                {
                    x = x/length;
                    y = y/length;
                }
            }

            double dotProduct(Vector2D const& other) const {
                return x * other.x + y * other.y;
            }
            double crossProduct(Vector2D const& other) const {
                return x * other.y - y * other.x;
            }

            double angleBetween(Vector2D const& other) const {
                double m1 = magnitude();
                double m2 = other.magnitude();

                if(m1 == 0 || m2 == 0) return 0;

                double val = dotProduct(other) / (m1 * m2);
                val = std::min(1.0, val);
                val = std::max(-1.0, val);
                return acos(val);
            }

            sf::Vector2f toSFMLVector() const {
                return sf::Vector2f(x, y);
            }

            friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
                os << "(" << v.x << ", " << v.y << ")";
                return os;
            }

            Vector2D operator+(Vector2D const& other) const {
                return Vector2D(x + other.x, y + other.y);
            }

            Vector2D operator-(Vector2D const& other) const {
                return Vector2D(x - other.x, y - other.y);
            }

            Vector2D operator*(double scalar) const {
                return Vector2D(x * scalar, y * scalar);
            }
            
            Vector2D operator/(double scalar) const {
                if(scalar == 0) return {x,y};
                return Vector2D(x / scalar, y / scalar);
            }

            // todo switch to epsilon comparisons in case of extreme use cases
            bool operator==(Vector2D const& other) const {
                return x == other.x && y == other.y;
            }

            bool operator!=(Vector2D const& other) const {
                return x != other.x || y != other.y;
            }

            Vector2D& operator+=(Vector2D const& other) {
                x += other.x;
                y += other.y;
                return *this;
            }
            Vector2D& operator-=(Vector2D const& other) {
                x -= other.x;
                y -= other.y;
                return *this;
            }
            Vector2D& operator*=(double scalar) {
                x *= scalar;
                y *= scalar;
                return *this;
            }
            Vector2D& operator/=(double scalar) {
                if(scalar != 0) {
                    x /= scalar;
                    y /= scalar;
                }
                return *this;
            }

            Vector2D operator-() const {
                return {-x, -y};
            }
};