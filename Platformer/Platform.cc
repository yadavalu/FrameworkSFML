#include "Platform.hh"

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
    rect.setSize(size);
    rect.setOrigin(size/2.0f);
    rect.setPosition(position);
    rect.setTexture(texture);
}

Platform::~Platform()
{
}

Collision Platform::GetCollider() const
{
    return Collision(rect);
}


void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, states);
}
