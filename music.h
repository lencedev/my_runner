/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** music
*/

#include "game.h"

#ifndef MUSIC_H_
    #define MUSIC_H_
once_music_t create_once_music(void);
all_music_t create_all_music(void);

void music_swap(game_t *game);
void theme_music(sfMusic *music);

#endif /* !MUSIC_H_ */