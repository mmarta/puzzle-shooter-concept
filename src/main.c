#include "system/defines.h"
#include "system/graphics.h"
#include "obj/player.h"

int main() {
    SetTileTable(tiles);
    ClearVram();

    PlayerInit(0);
    activePlayer = 0;

    while(true) {
        WaitVsync(1);

        PlayerInput();
        PlayerUpdate();
    }

    return 0;
}
