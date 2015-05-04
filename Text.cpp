#include "Text.hpp"
#include <FTGL/ftgl.h>
#include "About.hpp"

bool Text::Draw()
{
    if (Hidden) {
        return true;
    }
    FTGLPixmapFont font(_FONT_LOCATION_.c_str());
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

void Text::SetHidden(bool isHidden)
{
    Text::Hidden = isHidden;
}

