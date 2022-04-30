#include "../../SpriteSheet/AnimatedSprite.hh"
#include "../Platform.hh"


int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Platformer test");

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
