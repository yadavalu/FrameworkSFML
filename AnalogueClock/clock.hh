#ifndef __CLOCK__FRAMEWORK__
#define __CLOCK__FRAMEWORK__

#include <SFML/Graphics.hpp>

class AnalogueClock : public sf::Drawable
{
  sf::Clock _clock;
  struct tm * ptm;
  unsigned time_left, x, y, radius;
  sf::CircleShape clock;
  sf::RectangleShape h_hand, m_hand, s_hand;
  void HandMove(sf::RectangleShape&);
public:
  AnalogueClock(unsigned, unsigned, unsigned, unsigned);
  ~AnalogueClock();
  void SetPosition(unsigned, unsigned);
  void SetSize(unsigned);
  void Start();
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
