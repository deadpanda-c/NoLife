#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <exception>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "scenes/SceneManager.hpp"
#include "ConfigLoader.hpp"

#define CONFIG_FOLDER "../config/"

#define INVALID_CONFIG_FOLDER(name) "Config folder is invalid: " + name

namespace graphical {
  class Window {
    public:
      class WindowException : public std::exception {
        public:
          WindowException(const std::string& message) : _message(message) {}
          const char* what() const noexcept override {
            return _message.c_str();
          }
        private:
          std::string _message;
      };
      Window(const std::string& title, unsigned int width, unsigned int height);
      ~Window();

      void init();
      void run();
      void processEvents();
      void update();
      void render();
    private:
      void loadConfig();
      std::string _title;
      unsigned int _width;
      unsigned int _height;
      std::shared_ptr<sf::RenderWindow> _window;

  };
}
