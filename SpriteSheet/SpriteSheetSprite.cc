#include "SpriteSheetSprite.hh"

SpriteSheetSprite::SpriteSheetSprite(std::string file, unsigned int _rows, unsigned int _columns, sf::Vector2f _size)
    : rows(_rows), columns(_columns), size(_size), currentrow(1), currentcolumn(1), faceright(true)
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
    delete &rows, &columns;
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
        currentcolumn = 0;
        //Animate(row[0]);
        Move(0, -scale);
        break;

    case sf::Keyboard::Down:
    case sf::Keyboard::S:
        currentcolumn = 0;
        //Animate(row[1]);
        Move(0, scale);
        break;

    case sf::Keyboard::Right:
    case sf::Keyboard::D:
        if (!faceright) {
            //sprite.setScale(-1, 0);
            rect.width = -abs(rect.width);
            faceright = true;
        }
        currentcolumn = 0;
        //Animate(row[2]);
        Move(scale, 0);
        break;

    case sf::Keyboard::Left:
    case sf::Keyboard::A:
        if (faceright) {
            //sprite.setScale(-1, 0);
            rect.width = -abs(rect.width);
            faceright = false;
        }
        currentcolumn = 0;
        //Animate(row[3]);
        Move(-scale, 0);
        break;
    }
}

// TODO: Check column == NULL
void SpriteSheetSprite::Animate(unsigned int row) 
{
    if (row != NULL) {
        if (currentrow != row) {
            rect.top += (row - currentrow) * size.y;
            currentrow = row;
        }
    }

    if (currentcolumn < columns) {
        rect.left = size.x * currentcolumn;
        currentcolumn++;
    } else {
        rect.left = 0;
        currentcolumn = 1;
    }

    sprite.setTextureRect(rect);
}


void SpriteSheetSprite::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void SpriteSheetSprite::SetPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec.x, vec.y);
}

sf::Vector2f SpriteSheetSprite::GetPosition() const
{
    return sprite.getPosition();
}

void SpriteSheetSprite::Move(float x, float y)
{
    sprite.move(x, y);
}

void SpriteSheetSprite::Move(sf::Vector2f vec)
{
    sprite.move(vec.x, vec.y);
}


void SpriteSheetSprite::SetFaceDir(bool faceright)
{
    this->faceright = faceright;
}

bool SpriteSheetSprite::GetFaceDir() const
{
    return faceright;
}

