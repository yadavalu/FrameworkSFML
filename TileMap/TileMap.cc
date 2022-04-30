#include "TileMap.hh"

TileMap::TileMap(std::string file_name, std::vector<std::vector<int>> _map, std::vector<sf::IntRect> _tiles, int _tile_height, int _tile_width)
  : map(_map), tiles(_tiles), tile_height(_tile_height), tile_width(_tile_width)
{
  tile_sheet.loadFromFile(file_name);
  tile.setTexture(tile_sheet);
}

TileMap::~TileMap()
{
}

void TileMap::Loop(sf::RenderWindow& window)
{
  for (int row = 0; row < map.size(); row++)
    for (int col = 0; col < map[0].size(); col++)
      {
	tile.setTextureRect(tiles[map[row][col] - 1]);
	tile.setPosition((row * tile_width), (col * tile_width));
      }
  window.draw(tile);
}
