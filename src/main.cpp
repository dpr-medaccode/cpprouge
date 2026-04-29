#include "cpprouge/mapa.h"
#include "raylib-cpp/raylib-cpp.hpp"

#include <iostream>

int main(void) {

    srand(time(nullptr));

    /*

    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight,
                          "raylib-cpp - basic window");

    SetTargetFPS(60);

    while (!window.ShouldClose()) {

        BeginDrawing();

        window.ClearBackground(raylib::Color::RayWhite());

        raylib::DrawText("Congrats! You created your first window!", 190, 200,
                         20, raylib::Color::LightGray());

        EndDrawing();
    }

    */

    std::cout << RAYLIB_VERSION << "\n";

    Mapa m = Mapa::nuevo(80, 80, 40);

    std::cout << m;

    return 0;
}