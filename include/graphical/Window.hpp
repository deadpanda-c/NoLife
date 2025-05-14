#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "scenes/SceneManager.hpp"

namespace graphical {
  class Window {
    public:
      Window(const std::string& title, unsigned int width, unsigned int height);
      ~Window();

      void init();
      void run();
      void processEvents();
      void update();
      void render();
    private:
      std::string _title;
      unsigned int _width;
      unsigned int _height;
      std::shared_ptr<sf::RenderWindow> _window;
  };
}
