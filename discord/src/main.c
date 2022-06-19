#include <Windows.h>

#define DllExport __declspec(dllexport)

DllExport int discord_initialize(const char* application_id, int auto_register, int auto_update)
{
     printf("Discord: Initializing...\n");
     return 0;
}