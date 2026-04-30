#ifndef ROOMEDITORSTATE_H
#define ROOMEDITORSTATE_H

#include "state.h"
#include "menustate.h" 
#include "playstate.h" 
#include "player.h"
#include <vector>

#define TILE_SIZE 32

#define MAX_ROWS 64
#define MAX_COLS 64 

typedef u_int16_t TileType;

class RoomEditorState : public State{
    private:
        std::vector<TileType> room;
        int rows;
        int cols;

        void resize_room(int new_rows, int new_cols);

    public:
        void begin();
        void end();

        void update();
        void draw();
};

#endif