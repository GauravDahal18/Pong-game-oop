#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player
{
private:
    float targetY;
    float currentSpeed;

public:
    AIPlayer();
    void Update(Ball& ball) override;
};

#endif // AIPLAYER_H