#include "Score.hpp"
#include "About.hpp"
#include <FTGL/ftgl.h>

bool Score::Draw()
{
    FTGLPixmapFont font("/usr/share/fonts/gnu-free/FreeSerif.ttf");
    FTPoint location(Score::XLocation,Score::YLocation);
    if(font.Error()){
        return false;
    }
    font.FaceSize(15);
    std::string text;
    text = "TVBG Version 0.7.4.3 | Created by Thomas Cope | Score = " + std::to_string(Score::GameScore);
    font.Render(text.c_str(),text.length(),location);
    return true;
}

void Score::AddScore(int points)
{
    Score::GameScore += points;
}

int Score::GetScore()
{
    return Score::GameScore;
}

Score::Score(JAMCT_Logger* in_logger, int startx, int starty): Entity(in_logger,startx,starty){
    //Nothing todo
}
