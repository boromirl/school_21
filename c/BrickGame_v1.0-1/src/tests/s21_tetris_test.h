#ifndef S21_TETRIS_TEST_H
#define S21_TETRIS_TEST_H

#include <check.h>
#include <stdio.h>

#include "../brick_game/tetris/include/tetris_backend.h"

// цвета вывода сообщений в терминале
#define RESET "\033[0m"
#define RED "\033[31m"
#define GRAY_BG "\033[100m"
#define GREEN_BG "\033[42m"
#define MAGENTA "\033[35m"
#define RED_BG "\033[41m"
#define WHITE "\033[97m"

Suite *suite_boolean_checks();
Suite *suite_fsm();
Suite *suite_backend();

#endif