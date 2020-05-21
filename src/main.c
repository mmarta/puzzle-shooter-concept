#include "system/defines.h"
#include "system/graphics.h"

u8 animTime = 0, y = 26, down = false;

int main() {
    SetTileTable(tiles);
    ClearVram();

    while(true) {
        WaitVsync(1);

        if(animTime >= 16) {
            if(down) {
                switch(animTime) {
                    case 16:
                        DrawMap(28, y, mapPlayerTwist75A);
                        DrawMap(28, y + 2, mapPlayerTwist75B);
                        break;
                    case 18:
                        DrawMap(28, y, mapPlayerTwist50C);
                        DrawMap(28, y + 2, mapPlayerTwist50D);
                        break;
                    case 20:
                        DrawMap(28, y, mapPlayerTwist50A);
                        DrawMap(28, y + 2, mapPlayerTwist50B);
                        break;
                    case 22:
                        DrawMap(28, y, mapPlayerTwist25A);
                        DrawMap(28, y + 2, mapPlayerTwist25B);
                        break;
                    case 24:
                        Fill(28, y, 2, 2, 0);
                        y += 2;
                        DrawMap(28, y, mapPlayerA);
                        animTime = 0;
                        if(y == 26) {
                            down = false;
                        }
                        break;
                }
            } else {
                switch(animTime) {
                    case 16:
                        DrawMap(28, y - 2, mapPlayerTwist25A);
                        DrawMap(28, y, mapPlayerTwist25B);
                        break;
                    case 18:
                        DrawMap(28, y - 2, mapPlayerTwist50A);
                        DrawMap(28, y, mapPlayerTwist50B);
                        break;
                    case 20:
                        DrawMap(28, y - 2, mapPlayerTwist50C);
                        DrawMap(28, y, mapPlayerTwist50D);
                        break;
                    case 22:
                        DrawMap(28, y - 2, mapPlayerTwist75A);
                        DrawMap(28, y, mapPlayerTwist75B);
                        break;
                    case 24:
                        Fill(28, y, 2, 2, 0);
                        y -= 2;
                        DrawMap(28, y, mapPlayerA);
                        animTime = 0;
                        if(y == 0) {
                            down = true;
                        }
                        break;
                }
            }
        } else {
            if(!animTime || animTime == 8) {
                DrawMap(28, y, mapPlayerA);
            } else if(animTime == 4 || animTime == 12) {
                DrawMap(28, y, mapPlayerB);
            }
        }

        animTime++;
    }

    return 0;
}
