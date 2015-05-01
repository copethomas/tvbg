#include "Text.hpp"
#include <FTGL/ftgl.h>

bool Text::Draw()
{
    FTGLPixmapFont font("/usr/share/fonts/gnu-free/FreeSerif.ttf");
    FTPoint location(Text::XLocation,Text::YLocation);
    if(font.Error()){
        return false;
    }
    font.FaceSize(Text::Size);
    font.Render(Text::DisplayText.c_str(),Text::DisplayText.length(),location);
    return true;
}

Text::Text(JAMCT_Logger* in_logger, int startx, int starty, int in_Size, std::string in_text): Entity(in_logger,startx,starty)
{
    Text::Size = in_Size;
    Text::DisplayText = in_text;
}
