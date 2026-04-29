#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <stdio.h>
#include "state.h"
#include "playstate.h"
#include "roomeditorstate.h"

class MenuState : public State{
    public:
        void begin();

        void update();
        void draw();
};

#endif