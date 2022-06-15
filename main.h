/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** main
*/

#include "game.h"

#ifndef MAIN_H_
    #define MAIN_H_

game_t game_create(sfRenderWindow *window, int n_ennemis, char *buf);
sfRenderWindow *create_window(unsigned int w, unsigned int h, char *title);

void game_loop(sfRenderWindow *window, game_t *game);
void music_swap(game_t *game);
void lvl_screen(sfRenderWindow *window, game_t *game);
void animate_menu(sfRenderWindow *window , game_t *game);
void score_init(sfRenderWindow *window, game_t *game);
void animation(sfRenderWindow *window ,game_t *game);
void end(sfRenderWindow *window, game_t *game);
void pause_game(sfRenderWindow *window, game_t *game);
void game_event(sfRenderWindow *window, sfEvent event, game_t *game);
void destroy(sfRenderWindow *window, game_t *game);
void theme_music(sfMusic *music);
int user_input(char const *av);
void i_text(void);
void delta_time(game_t *game, sfTime delta);

#endif /* !MAIN_H_ */
