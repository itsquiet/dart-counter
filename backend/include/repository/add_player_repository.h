#ifndef ADD_PLAYER_REPOSITORY_H
#define ADD_PLAYER_REPOSITORY_H
#include <sqlite3.h>

int player_create(sqlite3 *db, const char *name, int *out_player_id);

#endif // ADD_PLAYER_REPOSITORY_H