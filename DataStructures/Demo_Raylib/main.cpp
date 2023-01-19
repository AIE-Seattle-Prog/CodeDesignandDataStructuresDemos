#include "raylib-cpp.hpp"

#include "SpriteObject.h"

#include <vector>

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
    SetTargetFPS(60);

    SpriteObject player("res/tile_0040.png");
    player.localPosition = { 200,200 };

    std::vector<GameObject *> gObjs;
    gObjs.push_back(&player);

    while (!window.ShouldClose())
    {
        for (const auto & go : gObjs)
        {
            go->Update();
        }

        BeginDrawing();

        window.ClearBackground(RAYWHITE);

        ::DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        for (const auto & go : gObjs)
        {
            go->Draw();
        }

        EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}