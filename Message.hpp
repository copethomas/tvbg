#ifndef MESSAGE_HPP_INCLUDED
#define MESSAGE_HPP_INCLUDED
#include "Text.hpp"
#include <thread>
class Message: public Text {

private:
    int displayTime = 1000;
    std::thread TimeerThread;
    void Timer();

public:
    Message(JAMCT_Logger *in_logger,int startx,int starty,int in_Size, std::string in_text,int time);
    ~Message();

};


#endif // MESSAGE_HPP_INCLUDED
