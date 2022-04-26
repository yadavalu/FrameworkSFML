#ifndef __ANIMATED_SPRITE_FRAMEWORK_HH__
#define __ANIMATED_SPRITE_FRAMEWORK_HH__

#include "Animation.hh"


class AnimatedSprite: public sf::Drawable
{
public:
    AnimatedSprite(sf::Texture *, sf::Vector2u, float, float);
    ~AnimatedSprite();

    void Update(float dt);

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    Animation animation;
    
    sf::RectangleShape shape;

    unsigned int row;
    float velocity;
    // Not required if there are animations for left and right
    bool faceright;
};


#endif
