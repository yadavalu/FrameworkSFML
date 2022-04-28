#ifndef __MOTION_SPRITE_SHEET_FRAMEWORK_HH__
#define __MOTION_SPRITE_SHEET_FRAMEWORK_HH__

#include <iostream>
#include <SFML/Graphics.hpp>


struct Key
{
    sf::Keyboard::Key key;
    unsigned int row;
    float dx, dy;
};


#endif
