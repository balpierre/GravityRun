/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player class
*/

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "def/typedef.h"

#define FILENAME "../../assets/highscore.txt"

void highscore_write(uint score)
{
    int fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
    std::string asstr = std::to_string(score);

    if (!fd)
        return;
    write(fd, asstr.c_str(), asstr.length());
}

uint highscore_read(void)
{
    int fd = open(FILENAME, O_RDONLY);
    struct stat st;
    char *s;
    int score = 0;

    if (!fd || fstat(fd, &st) == -1)
        return (0);
    s = (char *)malloc(st.st_size + 2);
    if (!s)
        return (0);
    if (read(fd, s, st.st_size) == st.st_size);
        score = atoi(s);
    free(s);
    return ((uint)score);
}