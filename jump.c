/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** jump
*/

#include "game.h"

void jump(game_t *game)
{
    static int time = 1;
    int y = -(9.81 / 12 * time * time) + 30 * time - 440;

    if (!game->init.pause) {
        time++;
            if (-y >= 440) {
                game->sus.state = WALK;
                y = -440;
                time = 1;
            }
                game->sus.pos.y = -y;
                sfSprite_setPosition(game->sus.sprite, game->sus.pos);
    }
}
