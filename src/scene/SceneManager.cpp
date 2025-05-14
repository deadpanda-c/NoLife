#include "scenes/SceneManager.hpp"

scene::SceneManager::SceneManager() : _currentSceneName("") {
    // Constructor implementation
}

void scene::SceneManager::addScene(const std::string& name, std::shared_ptr<Scene> scene)
{
  if (_scenes.find(name) != _scenes.end())
    ERROR_SCENE_ALREADY_EXISTS(name);
  _scenes[name] = scene;
  std::cout << "Scene " << name << " added to SceneManager." << std::endl;
}

void scene::SceneManager::removeScene(const std::string& name)
{
  if (_scenes.find(name) == _scenes.end())
    ERROR_SCENE_NOT_FOUND(name);
  _scenes.erase(name);
}

std::shared_ptr<scene::Scene> scene::SceneManager::getScene(const std::string& name)
{
  auto it = _scenes.find(name);

  return (it != _scenes.end()) ? it->second : nullptr;
}
