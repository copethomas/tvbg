#include "Message.hpp"

Message::Message(JAMCT_Logger* in_logger, int startx, int starty, int in_Size, std::string in_text, int time): Text(in_logger,startx,starty,in_Size,in_text)
{
    Message::displayTime = time;
    std::thread TimerLauncher (&Message::Timer,this);
    std::swap(TimerLauncher, Message::TimeerThread);
}

void Message::Timer()
{
    std::chrono::milliseconds dura(Message::displayTime);
    std::this_thread::sleep_for(dura);
    Message::SetDead(true);
}
Message::~Message()
{
    TimeerThread.join();
}
