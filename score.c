/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** score
*/

#include "game.h"

char *my_itoa(int nb);

score_t create_score(int size, sfVector2f position)
{
    score_t score;

    score.text = sfText_create();
    score.font = sfFont_createFromFile("font.ttf");
    score.size = size;
    score.score = 0;
    score.boost = 1;
    score.timer = 0;
    score.best = 0;
    score.temp_score = score.score;
    sfText_setCharacterSize(score.text, score.size);
    sfText_setString(score.text, "0");
    sfText_setFont(score.text, score.font);
    sfText_setColor(score.text, sfBlack);
    sfText_setPosition(score.text, position);
    return score;
}

void best_score(sfRenderWindow *window, game_t *game)
{
    if (!game->init.pause) {
        if (game->score.score > game->best_score.score)
            game->best_score.score = game->score.score;

        sfText_setString(game->best_score.text, \
                    my_itoa(game->best_score.score));
        }
    sfRenderWindow_drawText(window ,game->best_score.text, NULL);
}

void score_init(sfRenderWindow *window, game_t *game)
{
    if (!game->init.pause) {
        game->score.timer += game->delta_time;
        if (game->score.timer > 0.6 / game->score.boost) {
            game->score.score++;
            game->score.timer = 0;
        }
            sfText_setString(game->score.text, my_itoa(game->score.score));
    }
    best_score(window, game);
    sfRenderWindow_drawText(window ,game->score.text, NULL);
}
