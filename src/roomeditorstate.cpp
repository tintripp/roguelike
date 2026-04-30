#include "roomeditorstate.h"

void RoomEditorState::resize_room(int new_rows, int new_cols){
    auto temp = room;

    room.resize(new_rows * new_cols, TileType::AIR);

    for (int r = 0; r < new_rows; r++){
        for (int c = 0; c < new_cols; c++){
            TileType tile = temp[r * cols + c];

            if (c >= cols || r >= rows)
                tile = TileType::AIR;

            room[r * new_cols + c] = tile;
        }
    }

    rows = new_rows;
    cols = new_cols;
}

void RoomEditorState::begin(){
    rows = 10;
    cols = 10;

    room = std::vector<TileType>(rows * cols);
    room.reserve(MAX_ROWS * MAX_COLS);
    
    brush = TileType::WALL;
}

void RoomEditorState::end(){

}

void RoomEditorState::update(){
    if (IsKeyPressed(KEY_BACKSLASH))
        next = new MenuState{};

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
        room[row * cols + col] = brush;
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        room[row * cols + col] = TileType::AIR;

    if (IsKeyPressed(KEY_ONE))
        brush = TileType::WALL;
    if (IsKeyPressed(KEY_TWO))
        brush = TileType::CONNECTION;

    // Resize
    if (IsKeyPressed(KEY_LEFT) && cols > 1)
        resize_room(rows, cols - 1);
    if (IsKeyPressed(KEY_RIGHT) && cols < MAX_COLS)
        resize_room(rows, cols + 1);
    if (IsKeyPressed(KEY_UP) && rows > 1)
        resize_room(rows - 1, cols);
    if (IsKeyPressed(KEY_DOWN) && rows < MAX_ROWS)
        resize_room(rows + 1, cols);
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
            Color color;
            if (tile == TileType::WALL)
                color = GRAY;
            if (tile == TileType::CONNECTION)
                color = YELLOW;

            if (tile > TileType::AIR)
                DrawRectangle(
                    c * TILE_SIZE, 
                    r * TILE_SIZE, 
                    TILE_SIZE, 
                    TILE_SIZE, 
                    color
                );
        }
    }

    DrawText("Room Editor", 10, 10, 30, WHITE);
}