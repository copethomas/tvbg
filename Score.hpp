#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED
#include "Entity.hpp"
class Score: public Entity {

private:
    int GameScore = 0;

public:
    bool Draw();
    void AddScore(int points);
    int GetScore();
    Score(JAMCT_Logger *in_logger,int startx,int starty);
};


#endif // SCORE_HPP_INCLUDED
