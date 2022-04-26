#include "../clock.hh"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Analogue Clock");
  AnalogueClock clock(300/*Seconds Left*/, window.getSize().x / 2.0f, window.getSize().y / 2.0f, 100/*radius*/);
  sf::Event event;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	      if (event.type == sf::Event::Closed) window.close();
      clock.Start();
      window.clear();
      window.draw(clock);
      window.display();
    }
}
