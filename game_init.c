/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-owen1.bolling
** File description:
** game_init
*/

#include "game_create.h"

init_t create_init(void)
{
    init_t init;

    init.menu = sfTrue;
    init.loose = sfFalse;
    init.game = sfFalse;
    init.alive = sfFalse;
    init.is_walking = sfTrue;
    init.lvl = sfFalse;
    init.m_game = sfFalse;
    init.m_end = sfFalse;
    init.hardcore = sfFalse;
    init.pause = sfFalse;
    return init;
}

sfRenderWindow *create_window(unsigned int w, unsigned int h, char *title)
{
    sfRenderWindow *window;

    sfVideoMode mode = {w, h, 32};
    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    return window;
}

game_t game_create(sfRenderWindow *window, int n_ennemis, char *buf)
{
    game_t game;

    game.cactus_1 = create_cactus("r/img/cactus.png");
    game.sus = create_rectangle("r/img/sus.png");
    game.menu = create_menu();
    game.score = create_score(50, (sfVector2f){600, 0});
    game.init = create_init();
    game.musics = create_all_music();
    game.ejecs = create_ejec_l();
    game.bg = create_bg_list();
    game.end_screen = create_end_screen();
    game.screen = create_screen();
    game.clock_delta = sfClock_create();
    game.once_music = create_once_music();
    game.mp = sfMouse_getPositionRenderWindow(window);
    game.ennemis_list = create_ennemis_list(n_ennemis, buf);
    game.nb_ennemis = n_ennemis;
    game.best_score = create_score(50, (sfVector2f){1000, 0});
    return game;
}
