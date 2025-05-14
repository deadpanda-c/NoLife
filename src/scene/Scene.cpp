#include "scenes/Scene.hpp"

scene::Scene::Scene(const std::string &configFile) : _configFile(configFile), _name("Scene") {
    loadConfig();
    Logging::Log("Scene initialized with config file: " + configFile);
}

scene::Scene::Scene(const scene::Scene &other) : _configFile(other._configFile), _name(other._name) {
    if (other._configLoader)
        _configLoader = std::make_shared<lib::ConfigLoader>(*other._configLoader);
}

std::map<std::string, std::string> scene::Scene::loadConfig()
{
  _configLoader = std::make_shared<lib::ConfigLoader>();
  if (_configFile.empty())
    throw SceneException(EMPTY_CONFIG_FILE_PATH);
  std::filesystem::path configPath = std::filesystem::current_path() / CONFIG_FOLDER / _configFile;
  if (!std::filesystem::exists(configPath))
    throw SceneException(INVALID_CONFIG_FILE_PATH);

  Logging::Log("Loading scene configuration from: " + configPath.string());

  _configLoader->loadFile(configPath.string());

  _name = _configLoader->getString("NAME");
  if (_name.empty())
    throw SceneException(INVALID_SCENE_NAME);
  return _configLoader->getConfig();
}

std::map<std::string, std::string> scene::Scene::init()
{
  std::cout << "Initializing scene: " << _name << std::endl;
  _config = std::make_shared<graphical::Config>();
  std::map<std::string, std::string> config;
  config = loadConfig();

  if (config.empty())
    throw SceneException(INVALID_SCENE_CONFIG);

  // search for "BACKGROUND_COLOR"
  auto it = config.find("BACKGROUND_COLOR");
  if (it != config.end()) {
    std::string color = it->second;
    std::cout << "Background color: " << color << std::endl;
    _config->setBackgroundColor(color);
  } else {
    throw SceneException(INVALID_SCENE_CONFIG);
  }
  return config;
}

void scene::Scene::update()
{
  // Update logic here
}

void scene::Scene::render()
{
}
