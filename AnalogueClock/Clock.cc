#include "Clock.hh"

AnalogueClock::AnalogueClock(unsigned _x, unsigned _y, unsigned _radius)
  : x(_x), y(_y), radius(_radius)
{ 
  current_time = std::time(0);
  
  h_hand.setOrigin(h_hand.getGlobalBounds().width / 2,
                   h_hand.getGlobalBounds().height);
  m_hand.setOrigin(m_hand.getGlobalBounds().width / 2,
                   m_hand.getGlobalBounds().height);
  s_hand.setOrigin(s_hand.getGlobalBounds().width / 2,
                   s_hand.getGlobalBounds().height);

  // Default Colour Scheme. To set manually, manually set Colour via SetColour
  SetColour(sf::Color::White, sf::Color::White, sf::Color::Red, sf::Color::Blue);
  SetPosition(x, y);
  SetSize(radius);
}

AnalogueClock::~AnalogueClock()
{
  delete ptm;
}

void AnalogueClock::HandMove(sf::RectangleShape& hand)
{
  hand.setPosition(hand.getPosition().x + hand.getOrigin().x, hand.getPosition().y + hand.getOrigin().y);
}

void AnalogueClock::SetColour(sf::Color h_colour, sf::Color m_colour, sf::Color s_colour, sf::Color c_clock)
{
  h_hand.setFillColor(h_colour);
  m_hand.setFillColor(m_colour);
  s_hand.setFillColor(s_colour);
  clock. setFillColor(c_clock );
}

void AnalogueClock::SetSize(unsigned _radius)
{
  radius = _radius;
  clock.setRadius(radius);
  h_hand.setSize(sf::Vector2f(2.f, 3*radius/4));
  m_hand.setSize(sf::Vector2f(1.5, radius/3));
  s_hand.setSize(sf::Vector2f(1.f, radius/2));
  // Since radius is changed, this function needs to be called here again
  SetPosition(x, y);
}

void AnalogueClock::SetPosition(unsigned _x, unsigned _y)
{
  x = _x; y = _y;
  clock.setPosition(x, y);
  h_hand.setPosition(x+radius, y+radius);
  m_hand.setPosition(x+radius, y+radius);
  s_hand.setPosition(x+radius, y+radius);
}

void AnalogueClock::SetTime(unsigned _h, unsigned _m, unsigned _s)
{
  time.h = _h;
  time.m = _m;
  time.s = _s;
  manual = true;
}

void AnalogueClock::SetTime(struct Time _time)
{
  time.h = _time.h;
  time.m = _time.m;
  time.s = _time.s;
  manual = true;
}

void AnalogueClock::Start()
{
  if (!manual)
    {
      ptm = localtime(&current_time);
      h_hand.setRotation(ptm->tm_hour*30 + (ptm->tm_min/2));
      m_hand.setRotation(ptm->tm_min*6 + (ptm->tm_sec/12));
      s_hand.setRotation(ptm->tm_sec*6);
    }
  else
    {
      h_hand.setRotation((GetTime().h*30) + (GetTime().m/2));
      m_hand.setRotation((GetTime().m*6) + (GetTime().s/12));
      s_hand.setRotation((GetTime().s*6));
    }
}

void AnalogueClock::Loop()
{
  if (manual)
    {
    unsigned h = GetTime().h;
    unsigned m = GetTime().m;
    unsigned s = GetTime().s;
    if (_clock.getElapsedTime().asSeconds() >= 1)
      {
        time_passed++;
        if (time_passed % 3600 == 0) h++;
        if (time_passed % 60 == 0) { h += (m/12); m++; }
        else                       { m += (s/12); s++; }
        SetTime(h, m, s);
        _clock.restart();
      }
    }
}

void AnalogueClock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(clock);
  target.draw(h_hand);
  target.draw(m_hand);
  target.draw(s_hand);
}
