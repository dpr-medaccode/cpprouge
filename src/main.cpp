#include "cpprouge/mapa.h"
#include "raylib-cpp/raylib-cpp.hpp"

#include <iostream>

int main(void) {

    srand(time(nullptr));

    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "cpprouge");

    raylib::Camera3D camera(
        raylib::Vector3(0.0f, 10.0f, 10.0f), raylib::Vector3(0.0f, 0.0f, 0.0f),
        raylib::Vector3(0.0f, 1.0f, 0.0f), 45.0f, CAMERA_PERSPECTIVE);

    window.SetTargetFPS(60);

    while (!window.ShouldClose()) {

        BeginDrawing();

        window.ClearBackground(raylib::Color::RayWhite());

        /*raylib::DrawText("Congrats! You created your first window!", 190, 200,
                         20, raylib::Color::LightGray());*/

        camera.BeginMode();

        raylib::Vector3(-4.0f, 0.0f, 2.0f)
            .DrawCube(2.0f, 5.0f, 2.0f, raylib::Color::Red());

        raylib::Vector3(-4.0f, 0.0f, 2.0f)
            .DrawCubeWires(2.0f, 5.0f, 2.0f, raylib::Color::Gold());

        raylib::Vector3(-4.0f, 0.0f, -2.0f)
            .DrawCubeWires(3.0f, 6.0f, 2.0f, raylib::Color::Maroon());

        camera.EndMode();

        DrawFPS(10, 10);

        EndDrawing();
    }

    std::cout << RAYLIB_VERSION << "\n";

    Mapa m = Mapa::nuevo(80, 80, 40);

    std::cout << m;

    return 0;
}