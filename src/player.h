#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <raymath.h>

class Player{
    private:
        Rectangle rect;
        float speed;

    public:
        Player();

        void update();
        void draw();
};

#endif