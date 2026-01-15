#ifndef GAME_SERVICE_H
#define GAME_SERVICE_H
#include <sqlite3.h>
#include "model/x01_model.h"

int x01_create_game_with_players(sqlite3 *db, const int *player_ids, int num_players, const X01GameConfig *game_config, const X01PlayerConfig * player_configs, int *out_game_id);



#endif // GAME_SERVICE_H