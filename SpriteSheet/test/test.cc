#include "../AnimatedSprite.hh"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SpriteSheet Test");
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(512, 512));

    sf::Texture texture;
    texture.loadFromFile("./sprite.png");
    sf::Texture bg;
    bg.loadFromFile("./bg.jpg");
    bg.setRepeated(true);
    bg.setSmooth(true);
    sf::RectangleShape shape(sf::Vector2f(1440, 960));
    shape.setTexture(&bg);
    shape.setPosition(0, 0);

    AnimatedSprite sprite(&texture, sf::Vector2u(9, 4), 1, 50);
    sprite.SetPosition(sf::Vector2f(256, 256));
    float dt = 0;

    struct Key up { sf::Keyboard::Up, 0, 0, -2 };
    struct Key left { sf::Keyboard::Left, 1, -2, 0 };
    struct Key down { sf::Keyboard::Down, 2, 0, 2 };
    struct Key right { sf::Keyboard::Right, 3, 2, 0 };

    struct Key keys[4] = { up, down, right, left };
    sprite.SetKeys(keys);

    sf::Event event;
    sf::Clock clock;
    while (window.isOpen()) {
        dt = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            if (event.type == sf::Event::Resized) {
                view.setSize(512 * float(window.getSize().x)/float(window.getSize().y), 512 );
            }
        }
        
        sprite.Update(dt);

        view.setCenter(sprite.GetPosition());

        window.clear();
        window.setView(view);
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
