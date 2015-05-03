#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED
#include "Entity.hpp"
#include <string>
#include <FTGL/ftgl.h>
class Text: public Entity{

    protected:
        std::string DisplayText;
        int Size;
        bool Hidden = false;

    public:
        bool Draw();
        Text(JAMCT_Logger *in_logger,int startx,int starty,int in_Size, std::string in_text);
        void SetHidden(bool isHidden);

};


#endif // TEXT_HPP_INCLUDED
