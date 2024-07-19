#include<lib/AIPlayer.h>
#include <raylib.h>
#include <cmath>

AIPlayer::AIPlayer() : targetY(0), currentSpeed(0) {}

void AIPlayer::Update(Ball& ball) {
    if (ball.x > GetScreenWidth() / 2) {
        float predictedY = ball.y + (ball.speed_y * ((x - ball.x) / std::abs(ball.speed_x)));

        targetY = predictedY + GetRandomValue(-25, 25);
        float distanceToTarget = targetY - (y + height / 2);

        float desiredSpeed = speed * 1.5f * (distanceToTarget / 100.0f);

        currentSpeed = currentSpeed * 0.9f + desiredSpeed * 0.1f;

        y += currentSpeed;
        
        if (GetRandomValue(0, 100) < 5) {
            y += GetRandomValue(-15, 15);
        }
    }
    else {
        currentSpeed *= 0.95f;
        y += currentSpeed;
    }
    LimitMovement();
}