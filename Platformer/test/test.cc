#include "../../SpriteSheet/AnimatedSprite.hh"
#include "../Platform.hh"
#include "../Collision.hh"


int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Platformer test");

    sf::Texture texture;
    texture.loadFromFile("../../SpriteSheet/test/sprite.png");
    AnimatedSprite sprite(&texture, sf::Vector2u(9, 4), 1, 50);
    struct Key up { sf::Keyboard::Up, 0, 0, -2 };
    struct Key left { sf::Keyboard::Left, 1, -2, 0 };
    struct Key down { sf::Keyboard::Down, 2, 0, 2 };
    struct Key right { sf::Keyboard::Right, 3, 2, 0 };

    struct Key keys[4] = { up, down, right, left };
    sprite.SetKeys(keys);

    Collision collider(sprite.GetSprite());

    Platform platform(nullptr, sf::Vector2f(400, 200), sf::Vector2f(500, 200));
    Platform platform1(nullptr, sf::Vector2f(400, 200), sf::Vector2f(500, 0));

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        platform.GetCollider().CheckCollision(collider, 0);
        platform.GetCollider().CheckCollision(collider, 1);

        window.clear();
        window.draw(sprite);
        window.draw(platform);
        window.draw(platform1);
        window.display();
    }

    return 0;
}
