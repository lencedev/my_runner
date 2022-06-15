/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** music_init
*/

#include "game.h"

music_t create_music(char *title)
{
    music_t music;

    music.music = sfMusic_createFromFile(title);
    return music;
}

once_music_t create_once_music(void)
{
    once_music_t once_music;

    once_music.music_end = 1;
    once_music.music_game = 1;
    once_music.music_menu = 1;
    return once_music;
}

all_music_t create_all_music(void)
{
    all_music_t all_music;

    all_music.menu_theme = create_music("r/music/space_theme.wav");
    all_music.sus_walking = create_music("r/music/walking.wav");
    all_music.game_theme = create_music("r/music/noise.wav");
    all_music.sus_jump = create_music("r/music/jump.wav");
    all_music.end_theme = create_music("r/music/defeat.wav");
    all_music.hardcore_theme = create_music("r/music/hardcore.wav");
    return all_music;
}
