#include "player.h"

Player players[PLAYER_COUNT];
u8 activePlayer = 0;

void PlayerInit(u8 i) {
    players[i].x = 28;
    players[i].y = 13;
    players[i].score = 0;
    players[i].dir = NONE;
    players[i].active = true;
    DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerA);
}

void PlayerInput() {
    int controller = ReadJoypad(0); // TODO: Replace with actual read

    if(!players[activePlayer].active || players[activePlayer].dir) {
        return;
    }

    if(controller & BTN_LEFT && players[activePlayer].y < 25) {
        players[activePlayer].dir = LEFT;
        players[activePlayer].animTime = 24;
    } else if(controller & BTN_RIGHT && players[activePlayer].y > 1) {
        players[activePlayer].dir = RIGHT;
        players[activePlayer].animTime = 16;
    }
}

void PlayerUpdate() {
    if(!players[activePlayer].active) {
        return;
    }

    if(players[activePlayer].dir == RIGHT) {
        switch(players[activePlayer].animTime) {
            case 16:
                DrawMap(28, players[activePlayer].y - 2, mapPlayerTwist25A);
                DrawMap(28, players[activePlayer].y, mapPlayerTwist25B);
                break;
            case 18:
                DrawMap(28, players[activePlayer].y - 2, mapPlayerTwist50A);
                DrawMap(28, players[activePlayer].y, mapPlayerTwist50B);
                break;
            case 20:
                DrawMap(28, players[activePlayer].y - 2, mapPlayerTwist50C);
                DrawMap(28, players[activePlayer].y, mapPlayerTwist50D);
                break;
            case 22:
                DrawMap(28, players[activePlayer].y - 2, mapPlayerTwist75A);
                DrawMap(28, players[activePlayer].y, mapPlayerTwist75B);
                break;
            case 24:
                Fill(28, players[activePlayer].y, 2, 2, 0);
                players[activePlayer].y -= 2;
                DrawMap(28, players[activePlayer].y, mapPlayerA);
                players[activePlayer].animTime = 0;
                players[activePlayer].dir = NONE;
                return;
        }

        players[activePlayer].animTime++;
    } else if(players[activePlayer].dir == LEFT) {
        switch(players[activePlayer].animTime) {
            case 24:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerTwist75A);
                DrawMap(players[activePlayer].x, players[activePlayer].y + 2, mapPlayerTwist75B);
                break;
            case 22:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerTwist50C);
                DrawMap(players[activePlayer].x, players[activePlayer].y + 2, mapPlayerTwist50D);
                break;
            case 20:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerTwist50A);
                DrawMap(players[activePlayer].x, players[activePlayer].y + 2, mapPlayerTwist50B);
                break;
            case 18:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerTwist25A);
                DrawMap(players[activePlayer].x, players[activePlayer].y + 2, mapPlayerTwist25B);
                break;
            case 16:
                Fill(28, players[activePlayer].y, 2, 2, 0);
                players[activePlayer].y += 2;
                DrawMap(28, players[activePlayer].y, mapPlayerA);
                players[activePlayer].animTime = 0;
                players[activePlayer].dir = NONE;
                return;
        }

        players[activePlayer].animTime--;
    } else {
        switch(players[activePlayer].animTime) {
            case 0:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerA);
                break;
            case 4:
                DrawMap(players[activePlayer].x, players[activePlayer].y, mapPlayerB);
                break;
        }

        players[activePlayer].animTime++;
        if(players[activePlayer].animTime == 8) {
            players[activePlayer].animTime = 0;
        }
    }
}
