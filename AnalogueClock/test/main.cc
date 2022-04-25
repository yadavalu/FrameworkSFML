#include "../clock.hh"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Analogue Clock");
  AnalogueClock clock(300, 200, 200, 50);
  sf::Event event;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	if (event.type == sf::Event::Closed) window.close();
      window.clear();
      window.draw(clock);
      window.display();
    }
}
