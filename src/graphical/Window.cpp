#include "graphical/Window.hpp"

graphical::Window::Window(const std::string &title, unsigned int width, unsigned int height): _title(title), _width(width), _height(height)
{
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode({width, height}), title);

  Logging::Log("Window created with title: " + title);
  Logging::Log("Window size: " + std::to_string(width) + "x" + std::to_string(height));
}

graphical::Window::~Window()
{

}

void graphical::Window::loadConfig()
{
  _sceneManager = std::make_shared<scene::SceneManager>();
  _configLoader = std::make_shared<lib::ConfigLoader>();

  std::filesystem::path configPath = std::filesystem::current_path() / CONFIG_FOLDER;
  if (!std::filesystem::exists(configPath))
    throw WindowException(INVALID_CONFIG_FOLDER(configPath.string()));

  for (const auto &entry : std::filesystem::directory_iterator(configPath)) {
    if (entry.path().filename() == "scenes.cfg") {
      Logging::Log("Loading scenes configuration file");

      _configLoader->loadFile(entry.path().string());
      _availableScenesConfigFile = _configLoader->getStringList("SCENES_FILES", ",");


      for (const auto &scene : _availableScenesConfigFile) {
        Logging::Log("Available scene: " + scene);
        std::filesystem::path scenePath = configPath / scene;
        if (!std::filesystem::exists(scenePath))
          throw WindowException(INVALID_SCENE_FILE(scenePath.string()));

        _sceneManager->addScene(std::make_shared<scene::Scene>(scenePath.string()));
      }
    }
  }
}

void graphical::Window::initScenes()
{
  for (const auto &scene : _sceneManager->getSceneNames()) {
    std::map<std::string, std::string> sceneConfig = _sceneManager->getScene(scene)->init();
    _window->clear(sf::Color(_sceneManager->getScene(scene)->getConfig()->getBackgroundColor()));
  }
}

void graphical::Window::init()
{
  loadConfig();
  _sceneManager->setCurrentScene("menu");
  initScenes();
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
    event->visit([&](const auto& e) {
      using T = std::decay_t<decltype(e)>;

      if constexpr (std::is_same_v<T, sf::Event::Closed>) {
          _window->close();
      } else if constexpr (std::is_same_v<T, sf::Event::KeyPressed>) {
        if (e.code == sf::Keyboard::Key::A) {
          _sceneManager->setCurrentScene("menu_level");
        } else if (e.code == sf::Keyboard::Key::B) {
          _sceneManager->setCurrentScene("menu");
        }
      }
    });
  }
}

void graphical::Window::update()
{
  // initScenes();
}

void graphical::Window::render()
{
  _window->clear(sf::Color(_sceneManager->getCurrentScene()->getConfig()->getBackgroundColor()));
  _sceneManager->getCurrentScene()->render();
  _window->display();
}
