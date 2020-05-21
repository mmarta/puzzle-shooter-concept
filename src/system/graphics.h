#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "defines.h"

// Maps

extern const char mapPlayerA[];
extern const char mapPlayerB[];

extern const char mapPlayerTwist25A[];
extern const char mapPlayerTwist25B[];
extern const char mapPlayerTwist50A[];
extern const char mapPlayerTwist50B[];
extern const char mapPlayerTwist50C[];
extern const char mapPlayerTwist50D[];
extern const char mapPlayerTwist75A[];
extern const char mapPlayerTwist75B[];

extern const char mapPlayerTwist25[];
extern const char mapPlayerTwist50X[];
extern const char mapPlayerTwist50Y[];
extern const char mapPlayerTwist75[];

// The bare tiles themselves

extern const char tiles[];

void PrintVerticalPROGMEM(u8, u8, const char *);
void PrintVerticalRAM(u8, u8, const char *);
void PrintU8Vertical(u8, u8, u8);
void PrintU32Vertical(u8, u8, u32, u32);

#endif
