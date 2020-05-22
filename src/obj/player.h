#ifndef _PLAYER_H
#define _PLAYER_H

#include "../system/defines.h"
#include "../system/graphics.h"

#define PLAYER_COUNT 2

typedef enum {
    NONE, LEFT, RIGHT
} movement;

typedef struct {
    u8 x, y, active, animTime;
    u32 score;
    u16 scoreDelta;
    movement dir;
} Player;

extern Player players[];
extern u8 activePlayer;

void PlayerInit(u8);
void PlayerInput();
void PlayerUpdate();

#endif
