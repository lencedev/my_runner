/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** destroy
*/

#include "game.h"

void destroy(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_destroy(window);
    sfMusic_destroy(game->musics.menu_theme.music);
    sfMusic_destroy(game->musics.game_theme.music);
    sfMusic_destroy(game->musics.sus_walking.music);
    sfMusic_destroy(game->musics.end_theme.music);
    sfMusic_destroy(game->musics.sus_jump.music);
    sfMusic_destroy(game->musics.hardcore_theme.music);
    free(game->ejecs);
    free(game->bg);
    free(game->screen);
    free(game->clock_delta);
    free(game->ennemis_list);
}
