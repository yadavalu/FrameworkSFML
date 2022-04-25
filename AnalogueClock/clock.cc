#include "clock.hh"

AnalogueClock::AnalogueClock(unsigned _time_left, unsigned _x, unsigned _y,
		   unsigned _radius)
  : time_left(_time_left), x(_x), y(_y), radius(_radius)
{
  clock.setRadius(radius);
  clock.setFillColor(sf::Color::White);
  clock.setPosition(x, y);
  h_hand.setPosition(x+radius/2, y+radius/2);
  h_hand.setSize(sf::Vector2f(2, (1/2)*(radius/2)));
  h_hand.setFillColor(sf::Color::Red);
  m_hand.setPosition(x+radius/2, y+radius/2);
  m_hand.setSize(sf::Vector2f(2, (3/4)*(radius/2)));
  m_hand.setFillColor(sf::Color::Red);
  s_hand.setPosition(x+radius/2, y+radius/2);
  s_hand.setSize(sf::Vector2f(2, radius/2));
  s_hand.setFillColor(sf::Color::Red);
}

AnalogueClock::~AnalogueClock()
{
}

void AnalogueClock::HandMove(sf::RectangleShape& hand)
{
}

void AnalogueClock::Start()
{
  sf::Clock clock;
  int time_taken;
  do
    {
      if (clock.getElapsedTime().asSeconds() >= 1.0)
	{
	  time_left--;
	  time_taken++;
	  clock.restart();
	  if (time_taken % 3600 == 0)
	    HandMove(h_hand);
	  else if (time_taken % 60 == 0)
	    HandMove(m_hand);
	  else
	    HandMove(s_hand);
	}
    } while (time_left > 0);
}

void AnalogueClock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(clock);
  target.draw(h_hand);
  target.draw(m_hand);
  target.draw(s_hand);
}

