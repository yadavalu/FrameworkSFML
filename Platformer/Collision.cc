#include "Collision.hh"


Collision::Collision(sf::RectangleShape& rect)
    : rect(rect)
{
}

Collision::~Collision()
{
}

bool Collision::CheckCollision(Collision& body, float momentumtransfer)
{
    sf::Vector2f pos = body.GetPosition();
    sf::Vector2f halfsize = body.GetHalfSize();


    sf::Vector2f _pos = this->GetPosition();
    sf::Vector2f _halfsize = this->GetHalfSize();

    return false;
}

void Collision::Move(float dx, float dy)
{
    rect.move(dx, dy);
}

sf::Vector2f Collision::GetPosition() const
{
    return rect.getPosition();
}

sf::Vector2f Collision::GetHalfSize() const 
{
    return rect.getSize()/2.0f;
}
