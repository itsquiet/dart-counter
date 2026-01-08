#ifndef GAME_REPOSITORY_H
#define GAME_REPOSITORY_H
#include <sqlite3.h>

int game_create(sqlite3 *db, int *game_id);

#endif // GAME_REPOSITORY_H