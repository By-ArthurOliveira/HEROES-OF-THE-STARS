#include "raylib.h"
#include "app_controllers.hpp"
#include "app_imported_assets.hpp"
#include "math.h"

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

void DrawGameplay(Texture2D gameplay_background, Player &player)
{
    // Desenha fundo
    DrawTexture(gameplay_background, 0, 0, GRAY);

    // Calcula centro da nave na tela
    float shipW = (float)player.player_texture.width;
    float shipH = (float)player.player_texture.height;
    Vector2 shipCenter = { player.player_position_X + shipW*0.5f,
                           player.player_position_Y + shipH*0.5f };

    // Offset do boost em relação ao centro da nave (atrás): vetor apontando para baixo no sistema local
    Vector2 localBoostOffset = { 0.0f, shipH*0.5f + 10.0f };

    // Converte ângulo para radianos e rotaciona o offset
    float rad = player.player_rotation * DEG2RAD;
    Vector2 worldOffset = { localBoostOffset.x * cosf(rad) - localBoostOffset.y * sinf(rad),
                             localBoostOffset.x * sinf(rad) + localBoostOffset.y * cosf(rad) };

    // Posição do centro do boost no mundo
    Vector2 boostCenter = { shipCenter.x + worldOffset.x,
                             shipCenter.y + worldOffset.y };

    // Desenha nave com DrawTexturePro para usar o centro como origem de rotação
    Rectangle srcShip = { 0.0f, 0.0f, shipW, shipH };
    Rectangle dstShip = { shipCenter.x, shipCenter.y, shipW, shipH };
    Vector2 originShip = { shipW*0.5f, shipH*0.5f };
    
    // Desenha boost com mesma rotação e origem centrada
    float boostW = (float)player.player_boost_texture.width;
    float boostH = (float)player.player_boost_texture.height;
    
    Rectangle srcBoost = { 0.0f, 0.0f, boostW, boostH };
    Rectangle dstBoost = { boostCenter.x, boostCenter.y, boostW, boostH };
    Vector2 originBoost = { boostW*0.5f, boostH*0.5f };
        if (IsKeyDown(KEY_LEFT_SHIFT) && !pause_app)
                {
                    DrawTexturePro(player.player_boost_texture, srcBoost, dstBoost, originBoost, player.player_rotation, WHITE);
                }
    DrawTexturePro(player.player_texture, srcShip, dstShip, originShip, player.player_rotation, WHITE);
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