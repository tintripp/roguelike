#include "menustate.h"

void MenuState::begin() {
    printf("EPIC\n");
}

void MenuState::update() {
    if (GetKeyPressed() > 0)
        next = new PlayState{};
    if (IsKeyPressed(KEY_SEVEN))
        next = new RoomEditorState{};
}

void MenuState::draw() {
    ClearBackground(GRAY);
    DrawText("Menu", 10, 10, 30, BLACK);
}