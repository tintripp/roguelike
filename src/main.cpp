#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

/*
export RAYLIBPATH=${HOME}/Libraries/raylib/build/raylib

g++ -L${RAYLIBPATH} -I${RAYLIBPATH}/include src/main.cpp \
-lraylib -lGL -lpthread -ldl -lrt -lX11 -lm
*/

class Player{
    private:
        Rectangle rect;
        float speed;

    public:
        Player(){
            rect = {
                .x = 0,
                .y = 100,
                .width = 30,
                .height = 30,
            };
            speed = 200;
        }

        void update(){
            Vector2 vel = Vector2Normalize((Vector2){
                .x = (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
                .y = (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)),
            });

            rect.x += vel.x * speed * GetFrameTime();
            rect.y += vel.y * speed * GetFrameTime();
        }

        void draw(){
            DrawRectangleRec(rect, RED);
        }
};

class Game{
    private:
        Player player;
    
    public:
        Game(){}

        void begin(){
            InitWindow(1280, 720, "Roguelike");
            SetTargetFPS(30);

            player = (Player){};
        }

        void end(){
            CloseWindow();
        }

        void update(){
            player.update();
        }

        void draw(){
            ClearBackground(BLACK);

            player.draw();

            DrawText("Hello World", 10, 10, 30, BLUE);
        }

        void loop(){
            begin();
            while (!WindowShouldClose()){
                // UPDATE
                update();                

                // DRAW
                BeginDrawing();
                    draw();
                EndDrawing();
            }
            end();
        }
};

int main(void) {
    (Game){}.loop();
    return 0;
}
