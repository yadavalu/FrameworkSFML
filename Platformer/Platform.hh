#ifndef __PLATFORM_FRAMEWORK_HH__
#define __PLATFORM_FRAMEWORK_HH__

#include <SFML/Graphics.hpp>


class Platform: public sf::Drawable
{
public:
    Platform(sf::RectangleShape);
    ~Platform();

private:
    sf::RectangleShape rect;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
