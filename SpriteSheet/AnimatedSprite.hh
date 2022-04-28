#ifndef __ANIMATED_SPRITE_FRAMEWORK_HH__
#define __ANIMATED_SPRITE_FRAMEWORK_HH__

#include "Animation.hh"
#include "Motion.hh"


class AnimatedSprite: public sf::Drawable
{
public:
    AnimatedSprite(sf::Texture *, sf::Vector2u, float, float);
    ~AnimatedSprite();

    void SetKeys(struct Key *);
    void Update(float dt);
    
    sf::Vector2f GetSize() const;
    sf::Vector2f GetPosition() const;
    sf::RectangleShape GetSprite() const;


private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    Animation animation;
    
    sf::RectangleShape shape;

    struct Key *keys;
    struct Key currentkey;

    unsigned int row;
    float velocity;
    // Not required if there are animations for left and right
    bool faceright;
};


#endif
