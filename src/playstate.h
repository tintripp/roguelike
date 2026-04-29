#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <stdio.h>
#include "state.h"
#include "menustate.h" 
#include "player.h"

class PlayState : public State{
    private:
        Player player;

    public:
        void begin();

        void update();
        void draw();
};

#endif