#ifndef GAME_REPOSITORY_H
#define GAME_REPOSITORY_H
#include <sqlite3.h>

int game_create(sqlite3 *db, int *game_id, int game_mode, const int legs_to_win, const int sets_to_win);

#endif // GAME_REPOSITORY_H