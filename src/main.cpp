#include "scenes/SceneManager.hpp"

int main(void)
{
  scene::SceneManager sceneManager;

  sceneManager.addScene("scene1", std::make_shared<scene::Scene>());
  sceneManager.addScene("scene2", std::make_shared<scene::Scene>());
  return 0;
}
