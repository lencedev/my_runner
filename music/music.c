/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** music
*/

#include "music.h"

void theme_music(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

void music_game_loop(game_t *game)
{
    if (game->init.m_game && game->once_music.music_game > 0) {
        if (game->once_music.music_menu > 0) {
            sfMusic_stop(game->musics.menu_theme.music);
            game->once_music.music_menu = 0;
        }
        if (game->once_music.music_end == 0)
            sfMusic_stop(game->musics.end_theme.music);
        if (game->init.hardcore)
            theme_music(game->musics.hardcore_theme.music);
        if (!game->init.hardcore)
            theme_music(game->musics.game_theme.music);
        theme_music(game->musics.sus_walking.music);
        game->once_music.music_game = 0;
        game->once_music.music_end = 1;
        game->init.m_game = sfFalse;
    }
    return;
}

void music_end(game_t *game)
{
    if (game->init.m_end && game->once_music.music_end > 0) {
        if (game->once_music.music_game == 0 && game->init.hardcore) {
            sfMusic_stop(game->musics.hardcore_theme.music);
            sfMusic_stop(game->musics.sus_walking.music);
        } else {
            sfMusic_stop(game->musics.game_theme.music);
            sfMusic_stop(game->musics.sus_walking.music);
        }

        sfMusic_play(game->musics.end_theme.music);
        game->once_music.music_end = 0;
        game->once_music.music_game = 1;
        game->init.m_end = sfFalse;
    }
    return;
}

void music_swap(game_t *game)
{
    music_game_loop(game);
    music_end(game);
    return;
}
