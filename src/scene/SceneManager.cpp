#include "scenes/SceneManager.hpp"

scene::SceneManager::SceneManager() : _currentSceneName("") {
    // Constructor implementation
}

void scene::SceneManager::addScene(std::shared_ptr<Scene> scene)
{
  std::string name = scene->getName();

  if (_scenes.find(name) != _scenes.end())
    ERROR_SCENE_ALREADY_EXISTS(name);
  _scenes[name] = scene;

  Logging::Log("Scene added: " + name);
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

void scene::SceneManager::loadScene(const std::string &sceneName)
{
  auto it = _scenes.find(sceneName);
  if (it == _scenes.end())
    ERROR_SCENE_NOT_FOUND(sceneName);

  if (_currentSceneName != "")
    Logging::Log("Unloading scene: " + _currentSceneName);

  _currentSceneName = sceneName;
}

void scene::SceneManager::setCurrentScene(const std::string& name)
{
  if (_scenes.find(name) == _scenes.end())
    ERROR_SCENE_NOT_FOUND(name);

  _currentSceneName = name;
  Logging::Log("Current scene set to: " + name);
}
