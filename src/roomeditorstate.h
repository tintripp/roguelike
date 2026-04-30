#ifndef ROOMEDITORSTATE_H
#define ROOMEDITORSTATE_H

#include "state.h"
#include "menustate.h" 
#include "playstate.h" 
#include "player.h"
#include <vector>

#define TILE_SIZE 32

#define MAX_ROWS 20
#define MAX_COLS 32 

enum class TileType{
    AIR = 0,
    WALL,
    CONNECTION // Entrance/Exit, used to connect rooms in the algorithm.
};

class RoomEditorState : public State{
    private:
        std::vector<TileType> room;
        int rows;
        int cols;

        void resize_room(int new_rows, int new_cols);

        TileType brush;

    public:
        void begin();
        void end();

        void update();
        void draw();
};

#endif