#include <FTGL/ftgl.h>
#include "TextStats.hpp"

bool TextStats::Draw()
{
    TextStats::DisplayText = "E:" + std::to_string(TextStats::gameWorld->GetGameState()) + " - FPS:" + std::to_string(TextStats::gameWorld->GetFPS());
    FTGLPixmapFont font("/usr/share/fonts/gnu-free/FreeSerif.ttf");
    FTPoint location(TextStats::XLocation,TextStats::YLocation);
    if(font.Error()){
        return false;
    }
    font.FaceSize(TextStats::Size);
    font.Render(TextStats::DisplayText.c_str(),TextStats::DisplayText.length(),location);
    return true;
}

TextStats::TextStats(JAMCT_Logger* in_logger, int startx, int starty, int in_Size, World* theWorld): Text(in_logger,startx,starty,in_Size,"null")
{
    TextStats::gameWorld = theWorld;
}
