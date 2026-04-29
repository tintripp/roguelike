#include "roomeditorstate.h"

void RoomEditorState::begin(){
    rows = 100;
    cols = 100;
    room = std::vector<TileType>(static_cast<TileType>(rows * cols));
}

void RoomEditorState::end(){

}

void RoomEditorState::update(){
    Vector2 mp = GetMousePosition();
    int col = static_cast<int>(mp.x) / TILE_SIZE;
    int row = static_cast<int>(mp.y) / TILE_SIZE;

    DrawRectangle(
        col * TILE_SIZE, 
        row * TILE_SIZE, 
        TILE_SIZE, 
        TILE_SIZE, 
        Color{.r = 255, .a = 128}
    );

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        room[row * cols + col] = 1;

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        room[row * cols + col] = 0;
}

void RoomEditorState::draw(){
    ClearBackground(BLACK);

    // draw tiles
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            TileType tile = room[r * cols + c];
            if (tile > 0)
                DrawRectangle(
                    c * TILE_SIZE, 
                    r * TILE_SIZE, 
                    TILE_SIZE, 
                    TILE_SIZE, 
                    GRAY
                );
        }
    }

    DrawText("Room Editor", 10, 10, 30, WHITE);
}