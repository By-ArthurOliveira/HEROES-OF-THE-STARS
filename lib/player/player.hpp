#include "raylib.h"

#include <stdio.h>

typedef struct Player
{
    Texture2D player_texture;
    float player_position_X;
    float player_position_Y;
    float speed;
    int health;

    Texture2D player_boost_texture;
    float player_boost_texture_X;
    float player_boost_texture_Y;
} Player;

Player CreatePlayer()
{
    Player player;
    player.player_texture = LoadTexture("assets/player/player_texture.png");
    player.player_position_X = ((GetScreenWidth() / 2.0f) - (player.player_texture.width / 2.0f));
    player.player_position_Y = ((GetScreenHeight() / 2.0f) - (player.player_texture.height / 2.0f));
    player.speed = 2.5f;
    player.health = 100;

    player.player_boost_texture = LoadTexture("assets/player/player_boost_texture.png");
    player.player_boost_texture_X = player.player_position_X + 50;
    player.player_boost_texture_Y = player.player_position_Y + 85;

    return player;
}