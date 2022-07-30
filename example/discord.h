#ifndef DISCORD_H
#define DISCORD_H

#include <stdbool.h>

#pragma comment(lib, "discord.dll")

typedef struct discord {
     const char* application_id;
} discord_t;

bool discord_initialize(discord_t *discord);

#endif