#pragma once

#include <iostream>
#include <string>
#include <ctime>

/**
* @brief Logging class for logging messages with timestamps.
*
* This class provides static methods to log messages with different severity levels
* (info, error, warning) along with a timestamp.
*/
class Logging
{
  public:
      /**
      * @brief Logs an info message with a timestamp.
      * @param message The message to log.
      */
      static void Log(const std::string& message)
      {
        time_t now = time(0);
        char* dt = ctime(&now);

        std::string dateTime(dt);
        dateTime.pop_back();

        std::cout << "\033[1;34m" << "[" << dateTime << "]: " << "\033[0m" << message << std::endl;
      }

      /**
      * @brief Logs an error message with a timestamp.
      * @param message The message to log.
      */
      static void LogError(const std::string& message)
      {
        time_t now = time(0);
        char* dt = ctime(&now);

        std::string dateTime(dt);
        dateTime.pop_back();

        std::cout << "\033[1;31m" << "[" << dateTime << "]: " << "\033[0m" << message << std::endl;
      }

      /**
      * @brief Logs a warning message with a timestamp.
      * @param message The message to log.
      */
      static void LogWarning(const std::string& message)
      {
        time_t now = time(0);
        char* dt = ctime(&now);

        std::string dateTime(dt);
        dateTime.pop_back();

        std::cout << "\033[1;33m" << "[" << dateTime << "]: " << "\033[0m" << message << std::endl;
      }
  private:
      time_t timestamp; // Timestamp for logging
};
