#ifndef __PLATFORM_FRAMEWORK_HH__
#define __PLATFORM_FRAMEWORK_HH__

#include <SFML/Graphics.hpp>

#include "Collision.hh"


class Platform: public sf::Drawable
{
public:
    Platform(sf::Texture *, sf::Vector2f, sf::Vector2f);
    ~Platform();

    Collision GetCollider() const;

private:
    sf::RectangleShape rect;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
