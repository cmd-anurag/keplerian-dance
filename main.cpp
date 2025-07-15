#include<SFML/Graphics.hpp>
#include<vector>
#include<cmath>

constexpr float G = 150.0f;


float calculateDistance(sf::Vector2f p1, sf::Vector2f p2)
{
    sf::Vector2f delta = p2 - p1; // p1 -> p2
    float squaredDistance = delta.x * delta.x + delta.y * delta.y;
    return sqrt(squaredDistance);
}

sf::Vector2f normalize(sf::Vector2f vector) 
{
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
    if(magnitude == 0) return {0,0};
    return vector / magnitude;
}


struct Body {
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float mass;
    float radius;
    sf::Color color;

    sf::VertexArray trail{sf::LineStrip};

    Body(sf::Vector2f position, float mass, float radius, sf::Color color) : position(position), mass(mass), radius(radius), color(color) {  
        velocity = {0,0};
        acceleration = {0,0};
    }

    void update(float dt)
    {
        velocity += acceleration * dt;
        position += velocity * dt;
        acceleration = {0,0};
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sim");

    std::vector<Body> bodies;

    Body body1({1150, 500}, 1, 20, sf::Color::Red);         // ORIBITING MASS
    Body body2({950, 500}, 100000, 30, sf::Color::Blue);       // CENTRAL MASS
    
    float orbitalVelocityMagnitude = sqrt(G * body2.mass / calculateDistance(body1.position, body2.position)); // root(Gm/r)
    
    sf::Vector2f radiusVector = body2.position - body1.position;
    sf::Vector2f normalizedRV = normalize(radiusVector);
    sf::Vector2f tangentialVector = {normalizedRV.y, -normalizedRV.x};

    body1.velocity = orbitalVelocityMagnitude * tangentialVector;
    body1.velocity *= 1.3f; // elliptical

    bodies.push_back(body1);
    bodies.push_back(body2);

    sf::Clock clock;

    while(window.isOpen()){

        float dt = clock.restart().asSeconds();

        // events
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }


        // physics updates
        for(int i = 0; i < bodies.size(); ++i) {
            for(int j = i + 1; j <  bodies.size(); ++j) {
                sf::Vector2f delta = bodies[j].position - bodies[i].position;
                
                float squaredDistance = delta.x * delta.x + delta.y * delta.y; // distance formula - (x2 - x1)^2 + (y2 - y1)^2
                float distance = sqrt(squaredDistance);
                float clampedDistance = std::max(distance, 5.0f);

                float forceMagnitude = G * bodies[i].mass * bodies[j].mass / (clampedDistance * clampedDistance);
                sf::Vector2f forceDirection = delta / clampedDistance;

                sf::Vector2f acc1 = (forceMagnitude / bodies[i].mass) * forceDirection;
                sf::Vector2f acc2 = (forceMagnitude / bodies[j].mass) * -forceDirection; // equal but opposite accleeration

                bodies[i].acceleration += acc1;
                bodies[j].acceleration += acc2;
            }
        }

        for(Body &body: bodies) {
            

            body.trail.append(sf::Vertex(body.position, sf::Color::White));

            if(body.trail.getVertexCount() > 1500) {
                sf::VertexArray newTrail{sf::LineStrip};

                for(size_t i = 1; i < body.trail.getVertexCount(); ++i)
                {
                    newTrail.append(body.trail[i]);
                }
                body.trail = std::move(newTrail);
            }
            body.update(dt);
        }

        // rendering
        window.clear();
        for(auto &body : bodies) {
            
            window.draw(body.trail);
            sf::CircleShape circle(body.radius);
            circle.setFillColor(body.color);
            circle.setPosition(body.position);
            circle.setOrigin(body.radius, body.radius);
            window.draw(circle);
            
        }
        window.setFramerateLimit(60);
        window.display();
    }

    return 0;
}