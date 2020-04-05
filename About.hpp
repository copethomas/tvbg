#ifndef ABOUT_HPP_INCLUDED
#define ABOUT_HPP_INCLUDED
#include <string>

const std::string _APP_VERSION_ = "0.8.8.9 (Alpha)";
const bool _DRAW_DEBUG_ = false;

#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #endif
#elif __linux
    const std::string _FONT_LOCATION_ = "/usr/share/fonts/truetype/freefont/FreeSerif.ttf";
#elif __unix // all unices not caught above
    const std::string _FONT_LOCATION_ = "/usr/share/fonts/truetype/freefont/FreeSerif.ttf";
#elif __posix
    const std::string _FONT_LOCATION_ = "/usr/share/fonts/truetype/freefont/FreeSerif.ttf";
#endif

#endif // ABOUT_HPP_INCLUDED
