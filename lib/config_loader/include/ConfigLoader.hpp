#pragma once

#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <filesystem>

#define FILE_NOT_FOUND_MSG "Failed to open config file"
#define MALFORMED_LINE_MSG "Malformed line in config file"
#define KEY_NOT_FOUND_MSG "Key not found in configuration"

#define CONFIG_FOLDER "../config/"

namespace lib {
  class ConfigLoader {
    public:
      class ConfigException : public std::exception {
        public:
          ConfigException(const std::string& detail = "")
            : _message(detail) {}
          const char* what() const noexcept override {
            return _message.c_str();
          }

        private:
          std::string _message;
      };
      ConfigLoader(const std::string& filepath);
      ConfigLoader() {}
      ~ConfigLoader() = default;

      void loadFile(const std::string& filepath);
      bool hasKey(const std::string& key) const;
      std::string getString(const std::string& key, const std::string& defaultValue = "") const;
      int getInt(const std::string& key, int defaultValue = 0) const;
      bool getBool(const std::string& key, bool defaultValue = false) const;
      std::map<std::string, std::string> getConfig() const;

      std::vector<std::string> getStringList(const std::string& key, const std::string& delimiter);

    private:
      std::string trim(const std::string& str);

      std::map<std::string, std::string> _config;
  };
}
