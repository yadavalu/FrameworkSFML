#ifndef __ANIMATION_FRAMEWORK_HH__
#define __ANIMATION_FRAMEWORK_HH__

#include <SFML/Graphics.hpp>


class Animation
{
public:
    Animation(sf::Texture *, sf::Vector2u, float);
    ~Animation();

    // Keep faceright bool true if there is a seperate sprite for left side
    void Animate(unsigned int, float, bool);
    sf::IntRect GetUVRect() const;
    
    sf::Vector2f GetSize() const;

private:
    sf::Vector2u count, current;
    
    float t, dt;

    sf::IntRect uvrect;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
