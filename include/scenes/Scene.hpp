#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "ConfigLoader.hpp"
#include "Logging.hpp"
#include "graphical/Config.hpp"

#define EMPTY_CONFIG_FILE_PATH "Config file path is empty"
#define INVALID_CONFIG_FILE_PATH "Invalid config file path"
#define INVALID_SCENE_NAME "Invalid scene name"
#define INVALID_SCENE_CONFIG "Invalid scene config"

namespace scene {
  class Scene {
    public:
      class SceneException : public std::exception {
        public:
          SceneException(const std::string &message) : _message(message) {}
          virtual const char* what() const noexcept override {
            return _message.c_str();
          }
        private:
          std::string _message;
      };

      Scene(const std::string &configFile);
      Scene(const Scene &other);
      ~Scene() {}

      virtual std::map<std::string, std::string> init();
      virtual void update();
      virtual void render();

      std::string getName() const {
        return _name;
      }
      std::shared_ptr<graphical::Config> getConfig() const {
        return _config;
      }
    private:
      std::map<std::string, std::string> loadConfig();
      std::string _configFile;
      std::string _name;
      std::shared_ptr<lib::ConfigLoader> _configLoader;
      std::shared_ptr<graphical::Config> _config;
  };
}
