#ifndef __TILEMAP__FRAMEWORK__HH__
#define __TILEMAP__FRAMEWORK__HH__

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

template<int rows, int cols> class TileMap : public sf::Drawable
{
  sf::Texture tile_sheet;
  std::vector<sf::IntRect> tiles;
  sf::Sprite tile;
  std::array<std::array<int, rows>, cols> map;
  unsigned tile_height, tile_width;
public:
  TileMap(std::string, std::array<std::array<int, rows>, cols>, std::vector<sf::IntRect>, int, int);
  ~TileMap();
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
