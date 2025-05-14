#include "Logging.hpp"

int main(void)
{
  Logging::Log("Hello, World!");

  Logging::LogError("This is an error message!");

  Logging::LogWarning("This is a warning message!");
  return 0;
}
