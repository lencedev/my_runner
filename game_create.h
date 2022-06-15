/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** game_create
*/

#include "game.h"

#ifndef GAME_CREATE_H_
    #define GAME_CREATE_H_

cactus_t create_cactus(char *title);
rect_t create_rectangle(char *title);
menu_t create_menu(void);
score_t create_score(int size, sfVector2f pos);
all_music_t create_all_music(void);
music_t create_music(char *title);
sprite_t *create_ejec_l(void);
bg_t *create_bg_list(void);
end_screen_t create_end_screen(void);
screen_t *create_screen(void);
once_music_t create_once_music(void);
ennemis_t *create_ennemis_list(int n_ennemis, char *buf);

#endif /* !GAME_CREATE_H_ */
