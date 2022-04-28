#include "Clock.hh"

AnalogueClock::AnalogueClock(unsigned _x, unsigned _y, unsigned _radius)
  : x(_x), y(_y), radius(_radius)
{ 
  h_hand.setOrigin(h_hand.getGlobalBounds().width / 2,
                   h_hand.getGlobalBounds().height - 25);
  h_hand.setFillColor(sf::Color::White);
  h_hand.setPosition(x,y);
  m_hand.setOrigin(m_hand.getGlobalBounds().width / 2,
                   m_hand.getGlobalBounds().height - 25);
  m_hand.setFillColor(sf::Color::White);
  m_hand.setPosition(x,y);
  s_hand.setOrigin(s_hand.getGlobalBounds().width / 2,
                   s_hand.getGlobalBounds().height - 25);
  s_hand.setFillColor(sf::Color::Red);
  s_hand.setPosition(x,y);
  h_hand.setSize(sf::Vector2f(5, 180));
  m_hand.setSize(sf::Vector2f(3, 240));
  s_hand.setSize(sf::Vector2f(2, 250));
  clock.setRadius(radius);
  clock.setFillColor(sf::Color::White);
  clock.setPosition(x, y);
}

AnalogueClock::~AnalogueClock()
{
  delete ptm;
}

void AnalogueClock::HandMove(sf::RectangleShape& hand)
{
  hand.setPosition(hand.getPosition().x + hand.getOrigin().x, hand.getPosition().y + hand.getOrigin().y);
}

void AnalogueClock::Start()
{
  long int current_time = std::time(NULL); // TODO: set Time
  ptm = localtime(&current_time);
  h_hand.setRotation(ptm->tm_hour*30 + (ptm->tm_min/2));
  m_hand.setRotation(ptm->tm_min*6 + (ptm->tm_sec/12));
  s_hand.setRotation(ptm->tm_sec*6);
}

void AnalogueClock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(clock);
  target.draw(h_hand);
  target.draw(m_hand);
  target.draw(s_hand);
}
