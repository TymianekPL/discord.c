#ifndef DISCORD_H
#define DISCORD_H

#include <stdbool.h>

#define DllExport __declspec(dllexport)

typedef struct discord
{
     const char *application_id;
     const char *token;
} discord_t;

bool discord_initialize(discord_t *discord);
bool discord_login(discord_t *discord);

#endif