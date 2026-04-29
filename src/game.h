#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "state.h"

class Game{
    private:
        State *state = nullptr;
    
    public:
        Game(){}

        void begin();
        void end();

        void set_state(State *new_state);

        void loop();
};

#endif