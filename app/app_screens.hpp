#include "raylib.h"
#include "app_controllers.hpp"
#include "app_imported_assets.hpp"

#include <stdio.h>

void DrawMainMenu(Texture2D main_menu_background, Sound switch_sound)
{
    DrawTexture(main_menu_background, 0, 0, LIGHTGRAY);
    switch (selected_option)
    {
    case 1:
        if (IsKeyPressed(KEY_ENTER))
        {
            current_app_state = GAMEPLAY;
        }

        DrawText("NOVO JOGO", 75, 325, 20, GOLD);
        DrawText("TABELA DE PONTUAÇÃO", 75, 375, 20, WHITE);
        DrawText("COMANDOS", 75, 425, 20, WHITE);
        DrawText("CREDITS", 75, 475, 20, WHITE);
        DrawText("SAIR DO JOGO", 75, 525, 20, WHITE);
        break;
    case 2:
        if (IsKeyPressed(KEY_ENTER))
        {
            current_app_state = SCOREBOARD;
        }

        DrawText("NOVO JOGO", 75, 325, 20, WHITE);
        DrawText("TABELA DE PONTUAÇÃO", 75, 375, 20, GOLD);
        DrawText("COMANDOS", 75, 425, 20, WHITE);
        DrawText("CREDITS", 75, 475, 20, WHITE);
        DrawText("SAIR DO JOGO", 75, 525, 20, WHITE);
        break;
    case 3:
        if (IsKeyPressed(KEY_ENTER))
        {
            current_app_state = COMMANDS;
        }

        DrawText("NOVO JOGO", 75, 325, 20, WHITE);
        DrawText("TABELA DE PONTUAÇÃO", 75, 375, 20, WHITE);
        DrawText("COMANDOS", 75, 425, 20, GOLD);
        DrawText("CREDITS", 75, 475, 20, WHITE);
        DrawText("SAIR DO JOGO", 75, 525, 20, WHITE);
        break;
    case 4:
        if (IsKeyPressed(KEY_ENTER))
        {
            current_app_state = CREDITS;
        }

        DrawText("NOVO JOGO", 75, 325, 20, WHITE);
        DrawText("TABELA DE PONTUAÇÃO", 75, 375, 20, WHITE);
        DrawText("COMANDOS", 75, 425, 20, WHITE);
        DrawText("CREDITS", 75, 475, 20, GOLD);
        DrawText("SAIR DO JOGO", 75, 525, 20, WHITE);
        break;
    case 5:
        if (IsKeyPressed(KEY_ENTER))
        {
            current_app_state = EXIT;
        }

        DrawText("NOVO JOGO", 75, 325, 20, WHITE);
        DrawText("TABELA DE PONTUAÇÃO", 75, 375, 20, WHITE);
        DrawText("COMANDOS", 75, 425, 20, WHITE);
        DrawText("CREDITS", 75, 475, 20, WHITE);
        DrawText("SAIR DO JOGO", 75, 525, 20, GOLD);
        break;
    }
}

void DrawGameplay(Texture2D gameplay_background, Player player, Asteroid asteroid)
{
    // Calcula centro da nave na tela
    float ship_widht = (float)player.player_texture.width;
    float ship_height = (float)player.player_texture.height;
    Vector2 ship_center = {player.player_position_X + ship_widht * 0.5f,
                           player.player_position_Y + ship_height * 0.5f};

    // Offset do boost em relação ao centro da nave (atrás): vetor apontando para baixo no sistema local
    Vector2 local_boost_offset = {0.0f, ship_height * 0.5f + 10.0f};

    // Converte ângulo para radianos e rotaciona o offset
    float rad = player.player_rotation * DEG2RAD;
    Vector2 world_offset = {local_boost_offset.x * cosf(rad) - local_boost_offset.y * sinf(rad),
                            local_boost_offset.x * sinf(rad) + local_boost_offset.y * cosf(rad)};

    // Posição do centro do boost no mundo
    Vector2 boost_center = {ship_center.x + world_offset.x,
                            ship_center.y + world_offset.y};

    // Desenha nave com DrawTexturePro para usar o centro como origem de rotação
    Rectangle src_ship = {0.0f, 0.0f, ship_widht, ship_height};
    Rectangle dst_ship = {ship_center.x, ship_center.y, ship_widht, ship_height};
    Vector2 origin_ship = {ship_widht * 0.5f, ship_height * 0.5f};

    // Desenha boost com mesma rotação e origem centrada
    float boost_widht = (float)player.player_boost_texture.width;
    float boost_height = (float)player.player_boost_texture.height;

    Rectangle src_boost = {0.0f, 0.0f, boost_widht, boost_height};
    Rectangle dst_boost = {boost_center.x, boost_center.y, boost_widht, boost_height};
    Vector2 origin_boost = {boost_widht * 0.5f, boost_height * 0.5f};

    DrawTexture(gameplay_background, 0, 0, GRAY);

    if (IsKeyDown(KEY_LEFT_SHIFT) && !pause_app)
    {
        DrawTexturePro(player.player_boost_texture, src_boost, dst_boost, origin_boost, player.player_rotation, WHITE);
    }

    DrawTextureEx(asteroid.asteroid_texture, {asteroid.asteroid_position_X, asteroid.asteroid_position_Y}, asteroid.asteroid_rotation, 1.0, WHITE);
    DrawTexturePro(player.player_texture, src_ship, dst_ship, origin_ship, player.player_rotation, WHITE);
}

void DrawScoreboard(Texture2D main_menu_background)
{
    DrawTexture(main_menu_background, 0, 0, LIGHTGRAY);
}

void DrawCommands(Texture2D main_menu_background)
{
    DrawTexture(main_menu_background, 0, 0, LIGHTGRAY);
}

void DrawCredits(Texture2D main_menu_background)
{
    DrawTexture(main_menu_background, 0, 0, LIGHTGRAY);
}

bool ExitApp()
{
    stop_app = true;
    return stop_app;
}