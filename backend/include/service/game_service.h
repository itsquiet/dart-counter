#ifndef GAME_SERVICE_H
#define GAME_SERVICE_H
#include <sqlite3.h>

int create_game_with_players(sqlite3 *db, const int *player_ids, int num_players, int *out_game_id);

#endif // GAME_SERVICE_H