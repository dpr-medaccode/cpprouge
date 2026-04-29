#include "raylib.h"
#include <iostream>
#include "cpprouge/mapa.h"

int main(void) {

    srand(time(nullptr));

	/*std::cout << "hola";

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight,
               "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20,
                 LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();*/

    Mapa m = Mapa::nuevo(80,80,40);

    std::cout << m;

    return 0;
}