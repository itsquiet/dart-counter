#ifndef GAME_PLAYER_REPOSITORY_H
#define GAME_PLAYER_REPOSITORY_H
#include <sqlite3.h>

int game_player_add(sqlite3 *db, int game_id, int player_id, int play_order);

#endif // GAME_PLAYER_REPOSITORY_H


