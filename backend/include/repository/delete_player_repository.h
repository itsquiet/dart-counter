#ifndef DELETE_PLAYER_REPOSITORY_H
#define DELETE_PLAYER_REPOSITORY_H

#include <sqlite3.h>

int delete_player(sqlite3 *db, int player_id);

#endif // DELETE_PLAYER_REPOSITORY_H