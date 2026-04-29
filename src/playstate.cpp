#include "playstate.h"

void PlayState::begin() {
    player = (Player){};
    printf("Hello\n");
}

void PlayState::update() {
    player.update();

    if (IsKeyPressed(KEY_BACKSPACE))
        next = new MenuState{};
}

void PlayState::draw() {
    ClearBackground(BLACK);

    player.draw();

    DrawText("Hello World", 10, 10, 30, BLUE);
}