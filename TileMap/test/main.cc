#include "../TileMap.hh"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Tile Map");

  unsigned width = 32, height = 32;
  const int tmap_width = 20, tmap_height = 20;

  sf::IntRect grass, path, stone, box;
  grass.left = 0;
  grass.top = 0;
  grass.width = width;
  grass.height = height;
  path.left = 32;
  path.top = 0;
  path.width = width;
  path.height = height;
  stone.left = 64;
  stone.top = 0;
  stone.width = width;
  stone.height = height;
  box.left = 96;
  box.top = 0;
  box.width = width;
  box.height = height;
    
  std::vector<sf::IntRect> tiles;
  tiles.push_back(grass);
  tiles.push_back(path);
  tiles.push_back(stone);
  tiles.push_back(box);
 
  std::vector<std::vector<int>> tmap =
    {{
      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 1 },
      { 1, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 1 },
      { 1, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 1 }, 
      { 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 1 }, 
      { 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 1 }, 
      { 1, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 1 },
      { 1, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 1 }, 
      { 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 1 }, 
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    }};
  
  TileMap tilemap("./tilemap.png", tmap, tiles, 32, 32);
  
  sf::Event event;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	if (event.type == sf::Event::Closed)
	  window.close();
      window.clear();
      tilemap.Loop(window);
      window.display();
    }
}
