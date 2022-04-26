#include <SFML/Graphics.hpp>

void Start(long int& currentTime, sf::Clock clock, sf::RectangleShape& h_hand, sf::RectangleShape& m_hand, sf::RectangleShape& s_hand)
{
  currentTime = clock.getElapsedTime().asSeconds();

  struct tm * ptm = localtime(&currentTime);

  h_hand.setRotation(ptm->tm_hour*30 + (ptm->tm_min/2) );
  m_hand.setRotation(ptm->tm_min*6 + (ptm->tm_sec/12) );
  s_hand.setRotation(ptm->tm_sec*6);
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Analogue Clock");
  sf::Vector2f windowCentre = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
  /*
  sf::RectangleShape h_hand(sf::Vector2f(5, 180)), 
      m_hand(sf::Vector2f(3, 240)), s_hand(sf::Vector2f(2, 250));
      */
     sf::RectangleShape h_hand, m_hand, s_hand;
     h_hand.setSize(sf::Vector2f(5, 180));
     m_hand.setSize(sf::Vector2f(3, 240));
     s_hand.setSize(sf::Vector2f(2, 250));
  int radius = 100, x = windowCentre.x, y = windowCentre.y;
  h_hand.setOrigin(h_hand.getGlobalBounds().width / 2,
                   h_hand.getGlobalBounds().height - 25);
  //h_hand.setSize(sf::Vector2f(5, 180));
  h_hand.setFillColor(sf::Color::White);
  h_hand.setPosition(x,y);
  m_hand.setOrigin(m_hand.getGlobalBounds().width / 2,
                   m_hand.getGlobalBounds().height - 25);
  //m_hand.setSize(sf::Vector2f(3, 240));
  m_hand.setFillColor(sf::Color::White);
  m_hand.setPosition(x,y);
  s_hand.setOrigin(s_hand.getGlobalBounds().width / 2,
                   s_hand.getGlobalBounds().height - 25);
  //s_hand.setSize(sf::Vector2f(2, 250));
  s_hand.setFillColor(sf::Color::Red);
  s_hand.setPosition(x,y);
  sf::Event event;
  sf::Clock clock;
  long int currentTime;
  while (window.isOpen())
  {
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed) window.close();

    //std::time_t currentTime = std::time(NULL);
    Start(currentTime, clock, h_hand, m_hand, s_hand);
    window.clear();
    window.draw(h_hand);
    window.draw(m_hand);
    window.draw(s_hand);
    window.display();
  }
  return 0;
}