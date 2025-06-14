#include "raylib.h"

#include <stdio.h>

int asteroids_counter = 0;
int asteroid_type;

typedef struct Asteroid
{
    Texture2D asteroid_texture;
    float asteroid_position_X;
    float asteroid_position_Y;
    float asteroid_rotation;
    float asteroid_speed;
} Asteroid;

Asteroid CreateAsteroids(int asteroid_type)
{
    Asteroid asteroid;
    switch (asteroid_type)
    {
    case 0:
        asteroid.asteroid_texture = LoadTexture("assets/asteroids/small.png");
        break;
    case 1:
        asteroid.asteroid_texture = LoadTexture("assets/asteroids/small.png");
        break;
    case 2:
        asteroid.asteroid_texture = LoadTexture("assets/asteroids/medium.png");
        break;
    case 3:
        asteroid.asteroid_texture = LoadTexture("assets/asteroids/big.png");
        break;
    }
    asteroid.asteroid_position_X = GetRandomValue(0, 1366);
    asteroid.asteroid_position_Y = GetRandomValue(0, 768);
    asteroid.asteroid_rotation = 0.0f;
    asteroid.asteroid_speed = 2.5;
    return asteroid;
}