#include "graphical/Window.hpp"

graphical::Window::Window(const std::string &title, unsigned int width, unsigned int height): _title(title), _width(width), _height(height)
{
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode({width, height}), title);

  std::cout << "Creating window: " << title << std::endl;
}

graphical::Window::~Window()
{

}

void graphical::Window::init()
{

}

void graphical::Window::run()
{
  while (_window->isOpen()) {
    processEvents();
    update();
    render();
  }
}

void graphical::Window::processEvents()
{
  while (const std::optional event = _window->pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      _window->close();
      std::cout << "Window closed" << std::endl;
    }
  }
}

void graphical::Window::update()
{

}

void graphical::Window::render()
{
  _window->clear();
  _window->display();
}
