#include "SpriteSheetSprite.hh"

SpriteSheetSprite::SpriteSheetSprite(std::string file, unsigned int _rows, unsigned int _columns, sf::Vector2f _size)
    : rows(_rows), columns(_columns), size(_size), currentrow(1), currentcolumn(1)
{
    if (!texture.loadFromFile(file)) std::cerr << "Error: File (" << file << ") not found.\n";

    rect.left = 0;
    rect.top = 0;
    rect.width = size.x;
    rect.height = size.y;

    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
}

SpriteSheetSprite::~SpriteSheetSprite()
{
    delete &sprite, &texture;
    delete &rect, &rows, &columns;
}

void SpriteSheetSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void SpriteSheetSprite::EventMove(sf::Keyboard::Key key, int scale, int row[])
{
    switch (key) {
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
        if (row[0] != currentrow) {
            rect.top += (row[0] - currentrow) * size.y;
            currentrow = row[0];
        }
        currentcolumn = 0;
        Move(0, -scale);
        break;

    case sf::Keyboard::Down:
    case sf::Keyboard::S:
        if (row[1] != currentrow) {
            rect.top -= (row[1] - currentrow) * size.y;
            currentrow = row[1];
        }
        currentcolumn = 0;
        Move(0, scale);
        break;

    case sf::Keyboard::Right:
    case sf::Keyboard::D:
        if (row[2] != currentrow) {
            rect.top -= (row[2] - currentrow) * size.y;
            currentrow = row[2];
        }
        currentcolumn = 0;
        Move(scale, 0);
        break;

    case sf::Keyboard::Left:
    case sf::Keyboard::A:
        if (row[3] != currentrow) {
            rect.top -= (row[3] - currentrow) * size.y;
            currentrow = row[3];
        }
        currentcolumn = 0;
        Move(-scale, 0);
        break;
    }
}

// TODO: Check column == NULL
void SpriteSheetSprite::Animate(unsigned int column) 
{
    if (currentcolumn < columns) {
        rect.left = size.x * currentcolumn;
    } else {
        rect.left = 0;
    }

    sprite.setTextureRect(rect);

    currentcolumn++;
}


void SpriteSheetSprite::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void SpriteSheetSprite::SetPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec.x, vec.y);
}

void SpriteSheetSprite::Move(float x, float y)
{
    sprite.move(x, y);
}

void SpriteSheetSprite::Move(sf::Vector2f vec)
{
    sprite.move(vec.x, vec.y);
}
