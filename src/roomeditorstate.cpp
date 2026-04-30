#include "roomeditorstate.h"

void RoomEditorState::resize_room(int new_rows, int new_cols){
    // add padding / remove elements from the end of each row, based off of column.
    /*
        [1, 1, 1, 0       [1, 1, 1, 0, 0, 0
         0, 0, 1, 0   ->   0, 0, 1, 0, 0, 0
         1, 0, 1, 0]       1, 0, 1, 0, 0, 0]
    */

    auto temp = room;

    room.resize(new_rows * new_cols, 0);

    for (int r = 0; r < new_rows; r++){
        for (int c = 0; c < new_cols; c++){
            if (c < cols)
                room[r * cols + c] = temp[r * cols + c];
        }    
    }

    rows = new_rows;
    cols = new_cols;
}

void RoomEditorState::begin(){
    rows = 10;
    cols = 10;

    room = std::vector<TileType>(static_cast<TileType>(rows * cols));
    room.reserve(MAX_ROWS * MAX_COLS);
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

    // Draw
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        room[row * cols + col] = 1;
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        room[row * cols + col] = 0;

    // Resize
    if (IsKeyPressed(KEY_LEFT) && cols > 1){
        resize_room(rows, cols - 1);
        printf("%i\n", cols);
    }
    if (IsKeyPressed(KEY_RIGHT) && cols < MAX_COLS){
        resize_room(rows, cols + 1);
        printf("%i\n", cols);
    }
}

void RoomEditorState::draw(){
    ClearBackground(BLACK);

    // draw tiles
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            DrawRectangleLines(
                c * TILE_SIZE, 
                r * TILE_SIZE, 
                TILE_SIZE, 
                TILE_SIZE, 
                Color{.r = 255, .g = 255, .b = 255, .a = 64}
            );

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