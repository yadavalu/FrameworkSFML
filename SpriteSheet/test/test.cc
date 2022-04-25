#include "../SpriteSheetSprite.hh"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SpriteSheet Test");

    SpriteSheetSprite sprite("./ironman.jpg", 1, 4, sf::Vector2f(205, 254));
    int columns[4] = { 1, 1, 1, 1 };

    sf::Event event;
    sf::Clock clock;
    while (window.isOpen()) {
        window.setFramerateLimit(60);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            
            if (event.type == sf::Event::KeyPressed) {
                sprite.EventMove(event.key.code, 10, columns);
            }
        }

        if (clock.getElapsedTime().asSeconds() > 0.2) {
            sprite.Animate();
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
