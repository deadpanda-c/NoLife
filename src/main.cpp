#include "graphical/Window.hpp"

int main(void)
{
  graphical::Window window("NoLife", 800, 600);

  window.init();
  window.run();
  return 0;
}
