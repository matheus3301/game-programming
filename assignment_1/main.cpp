#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

// DATA STRUCTURES
struct Circle
{
  std::string name;
  float x, y, sx, sy, radius;
  int r, g, b;
};

struct Rectangle
{
  std::string name;
  float x, y, sx, sy, w, h;
  int r, g, b;
};

// GLOBAL VARIABLES

int window_height, window_width;

sf::Font font;
int font_sz, font_r, font_g, font_b;

std::vector<struct Circle> circles;
std::vector<struct Rectangle> rectangles;

// FUNCTIONS

bool readConfiguration()
{
  std::ifstream config("config.txt");
  std::string tmp;

  int rect_count = 0;
  int circle_count = 0;
  bool window_loaded = false, font_loaded = false;

  while (config >> tmp)
  {
    if (tmp == "Window")
    {
      config >> window_height >> window_width;
      window_loaded = true;
    }
    else if (tmp == "Font")
    {
      config >> tmp;

      if (!font.loadFromFile(tmp))
        return false;

      config >> font_sz >> font_r >> font_b >> font_b;

      font_loaded = true;
    }
    else if (tmp == "Circle")
    {
    }
    else if (tmp == "Rectangle")
    {
    }
    else
    {
      return false;
    }
  }

  std::cout << "Loaded " << rect_count << " Rectangles" << std::endl;
  std::cout << "Loaded " << circle_count << " Circles" << std::endl;

  return window_loaded && font_loaded;
}

int main(int argc, char *argv[])
{
  if (!readConfiguration())
  {
    std::cerr << "Error while reading the config.txt file";
    return 1;
  }

  return 0;
}

// sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
// sf::CircleShape shape(100.f);
// shape.setFillColor(sf::Color::Green);

// while (window.isOpen())
// {
//   sf::Event event;
//   while (window.pollEvent(event))
//   {
//     if (event.type == sf::Event::Closed)
//       window.close();
//   }

//   window.clear();
//   window.draw(shape);
//   window.display();
// }