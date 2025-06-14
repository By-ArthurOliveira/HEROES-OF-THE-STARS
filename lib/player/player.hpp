#include "raylib.h"

#include <stdio.h>

typedef struct Player
{
    Texture2D player_texture;
    float player_position_X;
    float player_position_Y;
    float player_rotation;
    float speed;
    int health;

    Texture2D player_boost_texture;
    float player_boost_texture_X;
    float player_boost_texture_Y;
    float player_boost_rotation;
} Player;

Player CreatePlayer()
{
    Player player;
    player.player_texture = LoadTexture("assets/player/player_texture.png");
    player.player_boost_texture = LoadTexture("assets/player/player_boost_texture.png");

    player.player_position_X = (GetScreenWidth() - player.player_texture.width) * 0.5f;
    player.player_position_Y = (GetScreenHeight() - player.player_texture.height) * 0.5f;

    player.player_rotation = 0.0f;
    player.speed = 2.5f;
    player.health = 100;

    return player;
}
