#include "../Animation.hh"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SpriteSheet Test");

    sf::Texture texture;
    texture.loadFromFile("./index.png");
    sf::Sprite sprite(texture);

    Animation animation(&texture, sf::Vector2u(9, 8), 1);
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
            
            if (event.type == sf::Event::KeyPressed) {
                
            }
        }
        
        animation.Animate(2, dt, true);
        sprite.setTextureRect(animation.GetUVRect());

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
