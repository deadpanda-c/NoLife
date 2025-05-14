#include "graphical/Config.hpp"

graphical::Config::Config()
{
  _backgroundColor = sf::Color(0, 0, 0);
  _frameRateLimit = 60;
  _windowWidth = 800;
  _windowHeight = 600;
}

graphical::Config::~Config()
{
  // Destructor
}

void graphical::Config::setBackgroundColor(const std::string &hex)
{
    std::string cleaned = hex;
    if (cleaned.starts_with('#'))
        cleaned = cleaned.substr(1);

    if (cleaned.size() != 6 && cleaned.size() != 8)
        throw std::invalid_argument("Hex string must be 6 (RGB) or 8 (RGBA) characters long.");

    unsigned int r, g, b, a = 255; // Default alpha to fully opaque

    std::stringstream ss;
    ss << std::hex << cleaned;

    if (cleaned.size() == 6) {
        unsigned int rgb;
        ss >> rgb;
        r = (rgb >> 16) & 0xFF;
        g = (rgb >> 8) & 0xFF;
        b = rgb & 0xFF;
    } else {
        unsigned int rgba;
        ss >> rgba;
        r = (rgba >> 24) & 0xFF;
        g = (rgba >> 16) & 0xFF;
        b = (rgba >> 8) & 0xFF;
        a = rgba & 0xFF;
    }
    _backgroundColor = sf::Color(r, g, b, a);
}

void graphical::Config::setFrameRateLimit(unsigned int limit)
{
  _frameRateLimit = limit;
  Logging::Log("Frame rate limit set to: " + std::to_string(limit));
}

void graphical::Config::setWindowSize(int width, int height)
{
  _windowWidth = width;
  _windowHeight = height;
  Logging::Log("Window size set to: " + std::to_string(width) + "x" +
               std::to_string(height));
}
