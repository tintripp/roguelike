#include "player.h"

Player::Player(){
    rect = {
        .x = 0,
        .y = 100,
        .width = 32,
        .height = 32,
    };
    speed = 200;
}

void Player::update(){
    Vector2 vel = Vector2Normalize((Vector2){
        .x = (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
        .y = (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)),
    });

    rect.x += vel.x * speed * GetFrameTime();
    rect.y += vel.y * speed * GetFrameTime();
}

void Player::draw(){
    DrawRectangleRec(rect, RED);
}