#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Logging.hpp"

namespace graphical {
  class Config {
    public:
      Config();
      ~Config();

      void setWindowSize(int width, int height);
      void setBackgroundColor(const std::string &hex);
      void setFrameRateLimit(unsigned int limit);

      sf::Color getBackgroundColor() const {
        return _backgroundColor;
      }

    private:
      sf::Color _backgroundColor;
      unsigned int _frameRateLimit;
      int _windowWidth;
      int _windowHeight;
  };
}
