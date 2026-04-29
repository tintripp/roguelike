#ifndef EPICSTATE_H
#define EPICSTATE_H

#include <stdio.h>
#include "state.h"
#include "playstate.h"

class MenuState : public State{
    public:
        void begin();

        void update();
        void draw();
};

#endif