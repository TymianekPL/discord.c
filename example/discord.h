#ifndef DISCORD_H
#define DISCORD_H

#include <stdbool.h>

#pragma comment(lib, "discord.dll")

bool discord_initialize(const char* application_id);

#endif