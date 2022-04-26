#include "Animation.hh"


Animation::Animation(sf::Texture *texture, sf::Vector2u count, float dt)
    : count(count), dt(dt), t(0)
{
    current.x = 0;
    uvrect.width = texture->getSize().x/count.x;
    uvrect.height = texture->getSize().y/count.y;
}

Animation::~Animation()
{
}

void Animation::Animate(unsigned int row, float dt, bool faceright)
{
    current.y = row;

    t += dt;
    if (t >= dt) {
        t -= dt;
        current.x++;

        // Don't use:
        // texture.setRepeat(true)
        if (current.x >= count.x) current.x = 0;
    }

    if (faceright) {
        uvrect.left = current.x * uvrect.width;
        uvrect.width = abs(uvrect.width);
    } else {
        uvrect.left = (current.x + 1) * abs(uvrect.width);
        uvrect.width = -abs(uvrect.width);
    }
    uvrect.top = current.y * uvrect.height;
}

sf::IntRect Animation::GetUVRect() const
{
    return uvrect;
}

sf::Vector2f Animation::GetSize() const
{
    return sf::Vector2f(uvrect.width, uvrect.height);
}

