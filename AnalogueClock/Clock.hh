#ifndef __CLOCK__FRAMEWORK__
#define __CLOCK__FRAMEWORK__

#include <SFML/Graphics.hpp>

struct Time
{
  unsigned h, m, s;
};

class AnalogueClock : public sf::Drawable
{
  bool manual = false;
  struct Time time;
  struct tm * ptm;
  unsigned x, y, radius, time_passed;
  long int current_time;
  sf::Clock _clock;
  sf::CircleShape clock;
  sf::RectangleShape h_hand, m_hand, s_hand;
  void HandMove(sf::RectangleShape&);
public:
  AnalogueClock(unsigned, unsigned, unsigned);
  ~AnalogueClock();
  void Loop();
  void SetTime(unsigned, unsigned, unsigned);
  void SetTime(struct Time);
  inline struct Time GetTime() { return time; }
  void SetPosition(unsigned, unsigned);
  void SetSize(unsigned);
  void Start();
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
