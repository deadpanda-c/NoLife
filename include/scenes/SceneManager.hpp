#pragma once

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <memory>

#include "Scene.hpp"

#define ERROR_SCENE_ALREADY_EXISTS(name) \
  throw SceneManagerException("Scene '" + name + "' already exists.")
#define ERROR_SCENE_NOT_FOUND(name) \
  throw SceneManagerException("Scene '" + name + "' not found.")


namespace scene {
  class SceneManager {
    public:

      class SceneManagerException : public std::exception {
        public:
          SceneManagerException(const std::string& message) : _message(message) {}
          virtual const char* what() const noexcept override {
            return _message.c_str();
          }
        private:
          std::string _message;
      };
      SceneManager();
      ~SceneManager() = default;

      void addScene(const std::string& name, std::shared_ptr<scene::Scene> scene);
      void removeScene(const std::string& name);

      std::shared_ptr<scene::Scene> getScene(const std::string& name);
    private:
      std::map<std::string, std::shared_ptr<scene::Scene>> _scenes;
      std::string _currentSceneName;
  };
}
