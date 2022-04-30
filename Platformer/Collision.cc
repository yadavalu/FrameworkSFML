#include "Collision.hh"

#include <iostream>


Collision::Collision(sf::RectangleShape rect)
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

    float dx = abs(pos.x - _pos.x);
    float dy = abs(pos.y - _pos.y);

    float intx = dx - (halfsize.x + _halfsize.x);
    float inty = dy - (halfsize.y + _halfsize.y);

    if (intx < 0 && inty < 0) {
        momentumtransfer = std::min(std::max(momentumtransfer, 0), 1);

        if (abs(intx) > abs(inty)) {
            if (dx > 0) {
                Move(intx * (1 - momentumtransfer), 0);
                body.Move(-intx * momentumtransfer, 0);
            } else {
                Move(-intx * (1 - momentumtransfer), 0);
                body.Move(intx * momentumtransfer, 0);
            }
        } else {
            if (dy > 0) {
                Move(0, inty * (1 - momentumtransfer));
                body.Move(0, -inty * momentumtransfer);
            } else {
                Move(0, -inty * (1 - momentumtransfer));
                body.Move(0, inty * momentumtransfer);
            }
        }
        return true;
    }

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
