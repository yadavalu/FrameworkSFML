#ifndef __SPRITE_SHEET_SPRITE_FRAMEWORK_HH__
#define __SPRITE_SHEET_SPRITE_FRAMEWORK_HH__

#include <iostream>

#include <SFML/Graphics.hpp>


class SpriteSheetSprite: public sf::Drawable 
{
public:
    SpriteSheetSprite(std::string, unsigned int, unsigned int, sf::Vector2f);
    ~SpriteSheetSprite();

    void SetPosition(float, float);
    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition() const;
    void Move(float, float);
    void Move(sf::Vector2f);
    void EventMove(sf::Keyboard::Key, int, int[]);
    void Animate(unsigned int row = NULL);

    void SetFaceDir(bool);
    bool GetFaceDir() const;

private:
    unsigned int rows, columns;
    unsigned int currentrow, currentcolumn;

    bool faceright;
    
    sf::Vector2f size;
    sf::IntRect rect;

    sf::Texture texture;
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};


#endif
