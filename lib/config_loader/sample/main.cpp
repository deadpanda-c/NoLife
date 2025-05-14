#include "ConfigLoader.hpp"

int main(void)
{
  std::string configFilePath = "../config/test.cfg";
  ConfigLoader configLoader(configFilePath);
  int intValue = 0;
  std::string stringValue;
  bool boolValue = false;
  std::vector<std::string> stringList;

  configLoader.getString("KEY", stringValue);
  configLoader.getInt("INTEGER", intValue);

}
