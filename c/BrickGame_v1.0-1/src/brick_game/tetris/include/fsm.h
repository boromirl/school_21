#ifndef FSM_H
#define FSM_H

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action,
  NoAction
} UserAction_t;

typedef enum {
  START,
  SPAWN,
  MOVING,
  SHIFTING,
  ATTACHING,
  PAUSE,
  GAMEOVER,
  EXIT_STATE
} GameState_t;

#endif