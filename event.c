/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** event
*/

#include "event.h"

void mouse_analyse_menu(sfRenderWindow *window, game_t *game)
{
    if (game->init.menu) {
        sfVector2i mp = sfMouse_getPositionRenderWindow(window);
        sfVector2f button = sfSprite_getPosition \
                    (game->menu.play_button.sprite);

        if (mp.x >= button.x && mp.x <= button.x + 400 && \
            mp.y >= button.y && mp.y <= button.y + 150) {
            game->init.lvl = sfTrue;
            game->init.menu = sfFalse;
            game->init.game = sfFalse;
        }
    }
}

void mouse_analyse_end(sfRenderWindow *window, game_t *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(window);
    sfVector2f b_l = sfRectangleShape_getPosition \
                            (game->end_screen.b_leave.shape);
    sfVector2f b_r = sfRectangleShape_getPosition \
                            (game->end_screen.b_replay.shape);

        if (mp.x >= b_r.x && mp.x <= b_r.x + 160 && \
        mp.y >= b_r.y && mp.y <= b_r.y + 160) {
            game->init.loose = sfFalse;
            game->init.alive = sfTrue;
            game->init.game = sfTrue;
            all_reset(game);
    }
        if (mp.x >= b_l.x && mp.x <= b_l.x + 150 && \
        mp.y >= b_l.y && mp.y <= b_l.y + 150) {
            sfRenderWindow_close(window);
    }
}

void mouse_event(sfRenderWindow *window, game_t *game)
{
    if (game->init.menu) {
        mouse_analyse_menu(window, game);
        mouse_analyse_ejec(window, game);
    }
    if (!game->init.menu && game->init.lvl)
        mouse_analyse_lvl(game);
    if (!game->init.game && game->init.loose)
        mouse_analyse_end(window, game);
    if (game->init.game && game->init.pause)
        mouse_analyse_pause(window, game);
}

void key_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.key.code == sfKeySpace && event.key.code == sfKeySpace && \
            game->init.game && game->sus.state == WALK \
                && !game->init.pause) {
        game->sus.state = JUMP;
        sfMusic_stop(game->musics.sus_jump.music);
        sfMusic_play(game->musics.sus_jump.music);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        if (game->init.game)
            game->init.pause = sfTrue;
        else
            sfRenderWindow_close(window);
    }
    if ((game->init.pause) && event.type == sfEvtKeyPressed \
        && event.key.code == sfKeyA)
        resume(game);

}

void game_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);

    if (event.type == sfEvtMouseButtonPressed)
        mouse_event(window, game);

    if (event.type == sfEvtKeyPressed)
        key_event(window, event, game);
}
