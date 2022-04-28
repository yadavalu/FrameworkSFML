#include "AnimatedSprite.hh"

AnimatedSprite::AnimatedSprite(sf::Texture *texture, sf::Vector2u count, float t, float velocity)
    : animation(texture, count, t), velocity(velocity), faceright(true)
{
    shape.setSize(animation.GetSize());
    shape.setOrigin(shape.getSize() / 2.0f);
    shape.setTexture(texture);
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::SetKeys(struct Key *keys)
{
    this->keys = keys;
}

void AnimatedSprite::Update(float dt)
{
    sf::Vector2f pos(0, 0);
    for (int i = 0; i < sizeof(keys)/2; i++) {
        if (sf::Keyboard::isKeyPressed(keys[i].key)) currentkey = keys[i];
    }

    pos.x += currentkey.dx * velocity * dt;
    pos.y += currentkey.dy * velocity * dt;
    row = currentkey.row;

    animation.Animate(row, dt, faceright);
    shape.setTextureRect(animation.GetUVRect());
    shape.move(pos);
}

sf::Vector2f AnimatedSprite::GetSize() const
{
    return animation.GetSize();
}

sf::Vector2f AnimatedSprite::GetPosition() const
{
    return shape.getPosition();
}

sf::RectangleShape AnimatedSprite::GetSprite() const
{
    return shape;
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
}
