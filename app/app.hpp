#include "raylib.h"
#include "app/app_screens.hpp"

#include <stdio.h>

int InitializeApp(){
    int screen_width = 1366;
    int screen_height = 768;

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_TOPMOST);
    SetTargetFPS(144);
    InitWindow(screen_width, screen_height, "HEROES OF THE STARS");
    InitAudioDevice();

    SetExitKey(KEY_NULL);

    AppAssets app_assets = CreateAppAssets();
    Player player = CreatePlayer();

    while (!stop_app){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (current_app_state){
        case MAIN_MENU:

            app_timer.time = GetTime();

            if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && selected_option > 1)
            {
                if (app_timer.time - app_timer.last_time > 0.22f)
                {
                    app_timer.last_time = app_timer.time;
                    PlaySound(app_assets.switch_sound);
                    selected_option--;
                }
            }
            else if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && selected_option < 5)
            {
                if (app_timer.time - app_timer.last_time > 0.22f)
                {
                    app_timer.last_time = app_timer.time;
                    PlaySound(app_assets.switch_sound);
                    selected_option++;
                }
            }

            DrawMainMenu(app_assets.main_menu_background, app_assets.switch_sound);
            break;
        case GAMEPLAY:

            if (IsKeyPressed(KEY_ESCAPE))
            {
                pause_app = !pause_app;
            }

            if (!pause_app)
            {
                if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && player.player_position_Y > 0)
                {
                    player.player_position_Y -= player.speed;
                }
                if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && player.player_position_Y < screen_height - player.player_texture.height)
                {
                    player.player_position_Y += player.speed;
                }
                if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && player.player_position_X > 0)
                {
                    player.player_position_X -= player.speed;
                }
                if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && player.player_position_X < screen_width - player.player_texture.width)
                {
                    player.player_position_X += player.speed;
                }

                if (IsKeyDown(KEY_LEFT_SHIFT))
                {
                    player.player_boost_texture_X = player.player_position_X + 50;
                    player.player_boost_texture_Y = player.player_position_Y + 85;
                    player.speed = 4.0;
                }else {
                    player.speed = 2.5;
                }

                DrawGameplay(app_assets.gameplay_background, player);

                if (IsKeyDown(KEY_LEFT_SHIFT))
                {
                    DrawTexture(player.player_boost_texture, player.player_boost_texture_X, player.player_boost_texture_Y, WHITE);
                }
            }else {
                DrawGameplay(app_assets.gameplay_background, player);

                DrawText("JOGO PAUSADO", 75, 400, 25, GOLD);
                DrawText("PRESSIONE ESC PARA CONTINUAR!", 75, 450, 25, GOLD);
            }
            break;
        case SCOREBOARD:

            if (IsKeyPressed(KEY_ESCAPE))
            {
                current_app_state = MAIN_MENU;
            }

            DrawScoreboard(app_assets.main_menu_background);
            break;
        case COMMANDS:

            if (IsKeyPressed(KEY_ESCAPE))
            {
                current_app_state = MAIN_MENU;
            }

            DrawCommands(app_assets.main_menu_background);
            break;
        case CREDITS:

            if (IsKeyPressed(KEY_ESCAPE))
            {
                current_app_state = MAIN_MENU;
            }

            DrawCredits(app_assets.main_menu_background);
            break;
        case EXIT:

            ExitApp();
            break;
        }

        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(player.player_boost_texture);
    UnloadTexture(player.player_texture);
    UnloadSound(app_assets.switch_sound);
    UnloadTexture(app_assets.gameplay_background);
    UnloadTexture(app_assets.main_menu_background);
    CloseWindow();
    return 0;
}