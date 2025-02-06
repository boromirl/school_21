#ifndef OBJECTS_H
#define OBJECTS_H

#include "fsm.h"

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct {
  int id;
  int orientation;
  int coords[4][2];
  int PoR[2];  // Point of Reference (относительно какой точки считаются
               // координаты)
  int color_code;
} Figure_t;

typedef struct {
  int **field;
  int score;
  int high_score;
  int level;
  int speed;
  int next;  // id of a next piece
  int tick;  // number of a frame in a sequence
  Figure_t current_figure;
  GameState_t state;
} Tetris_t;

#endif