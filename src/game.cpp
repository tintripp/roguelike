#include "game.h"

void Game::begin(){
    InitWindow(1280, 720, "Roguelike");
    SetTargetFPS(30);
}

void Game::end(){
    CloseWindow();
    if (state != nullptr)
        delete state;
}

void Game::set_state(State *new_state){
    if (state != nullptr){
        state->end();
        delete state;
    }

    state = new_state;
    state->begin();
}

void Game::loop(){
    begin();
    while (!WindowShouldClose()){
        // UPDATE
        state->update();
        
        // SWITCH STATE
        if (state->next != nullptr){
            State* next_state = state->next;
            state->next = nullptr;
            set_state(next_state);
        }

        // DRAW
        BeginDrawing();
            state->draw();
        EndDrawing();
    }
    end();
}