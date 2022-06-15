/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** ejec_mouse
*/

#include "game.h"

void check(sfVector2i mp, sfVector2f pos, sprite_t *ejec, game_t *game)
{
    if (mp.x >= pos.x && mp.x <= pos.x + ejec->size.x && mp.y >= pos.y \
                                        && mp.y <= pos.y + ejec->size.y) {
        if (game->init.menu) {
            game->sus.texture = sfTexture_createFromFile(ejec->id, NULL);
            sfSprite_setTexture(game->sus.sprite, game->sus.texture, sfTrue);
        }
    }
}

sfVector2f *create_get_position(game_t *game)
{
    sfVector2f *tab_pos = malloc(sizeof(sfVector2f) * 8);

    for (int i = 0; i != 8; i++)
        tab_pos[i] = sfSprite_getPosition(game->ejecs[i].sprite);
    return tab_pos;
}

void mouse_analyse_ejec(sfRenderWindow *window, game_t *game)
{
    sfVector2f *tab_pos = create_get_position(game);
    sfVector2i mp = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i != 8; i++) {
        sfVector2f position = {tab_pos[i].x - game->ejecs[i].origin.x, \
                                tab_pos[i].y - game->ejecs[i].origin.y};

        check(mp, position, &game->ejecs[i], game);
    }
}
