/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** main
*/

#include "main.h"

void game_loop(sfRenderWindow *window, game_t *game)
{
    if (game->init.game) {
        game->init.lvl = sfFalse;
        game->init.m_game = sfTrue,

        animation(window, game);
        score_init(window ,game);
    }
}

void game_scene(sfRenderWindow *window, game_t *game)
{
    music_swap(game);
    animate_menu(window, game);
    lvl_screen(window, game);
    game_loop(window, game);
    end(window, game);
    pause_game(window, game);
}

void menu(int n_ennemis, char *buf)
{
    sfEvent event;
    sfRenderWindow *window = create_window(1200, 600, "My Runner!");
    game_t game = game_create(window, n_ennemis, buf);
    sfTime delta;

    theme_music(game.musics.menu_theme.music);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        delta_time(&game, delta);
        while (sfRenderWindow_pollEvent(window, &event))
            game_event(window, event, &game);

        sfRenderWindow_clear(window, sfBlack);
        game_scene(window, &game);
        sfRenderWindow_display(window);
    }
    destroy(window, &game);
    return;
}

int main(int ac, char const **av)
{
    if (ac < 2 || ac > 2) {
        i_text();
        return 84;
    }
    user_input(av[1]);
    return 0;
    }
