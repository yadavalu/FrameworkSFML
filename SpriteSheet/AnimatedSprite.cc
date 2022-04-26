#include "AnimatedSprite.hh"

AnimatedSprite::AnimatedSprite(sf::Texture *texture, sf::Vector2u count, float t, float velocity)
    : animation(texture, count, t), velocity(velocity), faceright(true)
{
    shape.setSize(animation.GetSize());
    shape.setTexture(texture);
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::Update(float dt)
{
    sf::Vector2f pos(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) pos.x -= velocity * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) pos.x += velocity * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) pos.y += velocity * dt;

    if (pos.x == 0) row = 0;
    else {
        //row = 1;
        if (pos.x > 0) {
            //faceright = false;
            row = 3;
        } else {
            //faceright = true;
            row = 1;
        }
    }

    if (pos.y != 0) row = 2;

    animation.Animate(row, dt, faceright);
    shape.setTextureRect(animation.GetUVRect());
    shape.move(pos);
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
}
