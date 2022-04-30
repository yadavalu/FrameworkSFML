#include "Platform.hh"

Platform::Platform(sf::RectangleShape rect)
    : rect(rect)
{
}

Platform::~Platform()
{
}


void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, states);
}
