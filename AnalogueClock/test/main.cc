#include "../Clock.hh"
#include <iostream>
int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Analogue Clock");
  AnalogueClock aclock(window.getSize().x / 2.0f, window.getSize().y / 2.0f, 100/*radius*/);
  aclock.SetTime(12, 30, 4);
  sf::Event event;
  bool time_start = true;
  sf::Clock clock;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	      if (event.type == sf::Event::Closed) window.close();
      
      if (time_start)
        if (clock.getElapsedTime().asSeconds() <= 5)
          { aclock.Start(); aclock.Loop(); }
        else time_start = false;

      window.clear();
      window.draw(aclock);
      window.display();
    }
}
