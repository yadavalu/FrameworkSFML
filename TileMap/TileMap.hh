#ifndef __TILEMAP__FRAMEWORK__HH__
#define __TILEMAP__FRAMEWORK__HH__

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

class TileMap
{
  sf::Texture tile_sheet;
  std::vector<sf::IntRect> tiles;
  sf::Sprite tile;
  std::vector<std::vector<int>> map;
  unsigned tile_height, tile_width;
public:
  TileMap(std::string, std::vector<std::vector<int>>, std::vector<sf::IntRect>, int, int);
  ~TileMap();
  void Loop(sf::RenderWindow&);
};

#endif
