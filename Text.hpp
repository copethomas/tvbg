#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED
#include "Entity.hpp"
#include <string>
class Text: public Entity{

    private:
        std::string DisplayText;
        int Size;

    public:
        bool Draw();
        Text(JAMCT_Logger *in_logger,int startx,int starty,int in_Size, std::string in_text);

};


#endif // TEXT_HPP_INCLUDED
