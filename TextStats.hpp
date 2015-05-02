#ifndef TEXTSTATS_HPP_INCLUDED
#define TEXTSTATS_HPP_INCLUDED
#include "Text.hpp"
#include "World.hpp"
class TextStats : public Text{

private:
    World *gameWorld;

public:
    bool Draw();
    TextStats(JAMCT_Logger *in_logger,int startx,int starty,int in_Size, World *theWorld);

};


#endif // TEXTSTATS_HPP_INCLUDED
