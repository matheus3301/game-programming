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

// // GLOBAL VARIABLES
sf::RenderWindow window;
sf::Font font;

int window_height, window_width;

int font_sz, font_r, font_g, font_b;

std::vector<struct Circle> circles;
std::vector<struct Rectangle> rectangles;

// FUNCTIONS

void drawObjects(sf::RenderWindow &window)
{
  for (auto &c : circles)
  {
    sf::CircleShape circle(c.radius);
    circle.setFillColor(sf::Color(c.r, c.g, c.b));
    circle.setPosition(sf::Vector2f(c.x, c.y));

    if (circle.getGlobalBounds().left <= 0 || circle.getGlobalBounds().left + circle.getGlobalBounds().width >= window_width)
    {
      c.sx *= -1;
    }

    if (circle.getGlobalBounds().top <= 0 || circle.getGlobalBounds().top + circle.getGlobalBounds().height >= window_height)
    {
      c.sy *= -1;
    }

    sf::Text title;
    title.setFont(font);
    title.setString(c.name);
    title.setCharacterSize(font_sz);
    title.setFillColor(sf::Color(font_r, font_g, font_b));

    float x, y;
    x = circle.getGlobalBounds().left;
    y = circle.getGlobalBounds().top;

    x += (circle.getLocalBounds().width - title.getLocalBounds().width) / 2;
    y += (circle.getLocalBounds().height - title.getLocalBounds().height) / 2;

    title.setPosition(sf::Vector2f(x, y));

    window.draw(circle);
    window.draw(title);
  }
  for (auto &r : rectangles)
  {
    sf::RectangleShape rectangle(sf::Vector2f(r.w, r.h));
    rectangle.setFillColor(sf::Color(r.r, r.g, r.b));
    rectangle.setPosition(sf::Vector2f(r.x, r.y));

    if (rectangle.getGlobalBounds().left <= 0 || rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width >= window_width)
    {
      r.sx *= -1;
    }

    if (rectangle.getGlobalBounds().top <= 0 || rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height >= window_height)
    {
      r.sy *= -1;
    }

    sf::Text title;
    title.setFont(font);
    title.setString(r.name);
    title.setCharacterSize(font_sz);
    title.setFillColor(sf::Color(font_r, font_g, font_b));

    float x, y;
    x = rectangle.getGlobalBounds().left;
    y = rectangle.getGlobalBounds().top;

    x += (rectangle.getGlobalBounds().width - title.getGlobalBounds().width) / 2;
    y += (rectangle.getGlobalBounds().height - title.getGlobalBounds().height) / 2;

    title.setPosition(sf::Vector2f(x, y));

    window.draw(rectangle);
    window.draw(title);
  }
}

void updateObjects()
{
  for (auto &c : circles)
  {
    c.x += c.sx;
    c.y += c.sy;
  }

  for (auto &r : rectangles)
  {
    r.x += r.sx;
    r.y += r.sy;
  }
}

bool readConfiguration()
{
  std::ifstream config("config.txt");
  std::string tmp;

  int rectangle_count = 0;
  int circle_count = 0;
  bool window_loaded = false, font_loaded = false;

  while (config >> tmp)
  {
    if (tmp == "Window")
    {
      config >> window_width >> window_height;
      window_loaded = true;
    }
    else if (tmp == "Font")
    {
      config >> tmp;

      if (!font.loadFromFile(tmp))
        return false;

      config >> font_sz >> font_r >> font_g >> font_b;
      font_loaded = true;
    }
    else if (tmp == "Circle")
    {
      struct Circle circle;
      config >> circle.name >> circle.x >> circle.y >> circle.sx >> circle.sy >> circle.r >> circle.g >> circle.b >> circle.radius;

      circles.push_back(circle);
      circle_count++;
    }
    else if (tmp == "Rectangle")
    {
      struct Rectangle rectangle;
      config >> rectangle.name >> rectangle.x >> rectangle.y >> rectangle.sx >> rectangle.sy >> rectangle.r >> rectangle.g >> rectangle.b >> rectangle.w >> rectangle.h;

      rectangles.push_back(rectangle);
      rectangle_count++;
    }
    else
    {
      return false;
    }
  }

  std::cout << "Loaded " << rectangle_count << " Rectangles" << std::endl;
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
  std::cout << window_height << window_width << std::endl;
  window.create(sf::VideoMode(window_width, window_height), "Assignment 1");
  window.setFramerateLimit(60); // while we dont have timeDelta

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    window.clear(sf::Color::Black);

    drawObjects(window);
    updateObjects();

    window.display();
  }

  return 0;
}