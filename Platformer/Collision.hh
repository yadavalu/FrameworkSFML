#ifndef __COLLISION_FRAMEWORK_HH__
#define __COLLISION_FRAMEWORK_HH__

#include <SFML/Graphics.hpp>


class Collision
{
public:
    Collision(sf::RectangleShape&);
    ~Collision();

    bool CheckCollision(Collision&, float);
    sf::Vector2f GetPosition() const;
    sf::Vector2f GetHalfSize() const;

    void Move(float, float);


private:
    sf::RectangleShape& rect;
};


#endif
