#include "TileMap.hh"

TileMap<rows, cols>::TileMap(std::string file_name, std::array<std::array<int, rows>, cols> _map, std::vector<sf::IntRect> _tiles, int _tile_height, int _tile_width)
  : _map(map), tiles(_tiles), tile_height(_tile_height), tile_width(_tile_width)
{
  tile_sheet.loadFromFile(file_name);
  tile.setTexture(tile_sheet);
}

TileMap<rows, cols>::~TileMap()
{
}

void TileMap<rows, cols>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for (int row = 0; row < rows; row++)
    for (int col = 0; col < cols; col++)
      {
	tile.setTextureRect(tiles[map[row][col] - 1]);
	tile.setPosition((row * tile_width), (col * tile_width));
	target.draw(tile);
      }
  
}
