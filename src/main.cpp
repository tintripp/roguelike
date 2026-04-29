#include "game.h"
#include "playstate.h"

/*
export RAYLIBPATH=${HOME}/Libraries/raylib/build/raylib

g++ -L${RAYLIBPATH} -I${RAYLIBPATH}/include src/main.cpp \
-lraylib -lGL -lpthread -ldl -lrt -lX11 -lm
*/

int main(void) {
    Game game = Game{};
    game.set_state(new MenuState{});
    game.loop();
    return 0;
}
