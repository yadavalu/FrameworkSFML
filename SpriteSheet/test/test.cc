//#include "../Animation.hh"
#include "../AnimatedSprite.hh"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SpriteSheet Test");

    sf::Texture texture;
    texture.loadFromFile("./sprite.png");
    //sf::Sprite sprite(texture);

    //Animation animation(&texture, sf::Vector2u(9, 4), 1);
    AnimatedSprite sprite(&texture, sf::Vector2u(9, 4), 1, 10);
    float dt = 0;

    sf::Event event;
    sf::Clock clock;
    while (window.isOpen()) {
        dt = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
        
        //animation.Animate(2, dt, true);
        //sprite.setTextureRect(animation.GetUVRect());
        sprite.Update(dt);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
