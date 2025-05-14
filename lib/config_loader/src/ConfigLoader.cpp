#include "ConfigLoader.hpp"
#include <string>

lib::ConfigLoader::ConfigLoader(const std::string& filepath) {
  loadFile(filepath);
}

void lib::ConfigLoader::loadFile(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw ConfigException(FILE_NOT_FOUND_MSG + std::string(": ") + filepath);
  }

  std::string line;
  while (std::getline(file, line)) {
    line = trim(line);
    if (line.empty() || line[0] == '#' || line[0] == ';') continue;

    size_t delimiterPos = line.find('=');
    if (delimiterPos == std::string::npos) continue;

    std::string key = trim(line.substr(0, delimiterPos));
    std::string value = trim(line.substr(delimiterPos + 1));

    _config[key] = value;
  }
}

bool lib::ConfigLoader::hasKey(const std::string& key) const {
  return _config.find(key) != _config.end();
}

std::string lib::ConfigLoader::getString(const std::string& key, const std::string& defaultValue) const {
  auto it = _config.find(key);
  return it != _config.end() ? it->second : defaultValue;
}

int lib::ConfigLoader::getInt(const std::string& key, int defaultValue) const {
  try {
    return std::stoi(getString(key));
  } catch (...) {
    return defaultValue;
  }
}

bool lib::ConfigLoader::getBool(const std::string& key, bool defaultValue) const {
  std::string val = getString(key);
  std::transform(val.begin(), val.end(), val.begin(), ::tolower);

  if (val == "true" || val == "1" || val == "yes") return true;
  if (val == "false" || val == "0" || val == "no") return false;
  return defaultValue;
}

std::string lib::ConfigLoader::trim(const std::string& str) {
  const auto strBegin = str.find_first_not_of(" \t\r\n");
  if (strBegin == std::string::npos) return "";

  const auto strEnd = str.find_last_not_of(" \t\r\n");
  return str.substr(strBegin, strEnd - strBegin + 1);
}

std::vector<std::string> lib::ConfigLoader::getStringList(const std::string& key, const std::string& delimiter) {
  std::string value = getString(key);
  std::vector<std::string> result;
  size_t pos = 0;

  while ((pos = value.find(delimiter)) != std::string::npos) {
    result.push_back(trim(value.substr(0, pos)));
    value.erase(0, pos + delimiter.length());
  }
  if (!value.empty()) {
    result.push_back(trim(value));
  }
  return result;
}

std::map<std::string, std::string> lib::ConfigLoader::getConfig() const {
  return _config;
}

