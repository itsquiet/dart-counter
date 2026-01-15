#ifndef GAME_SERVICE_H
#define GAME_SERVICE_H
#include <sqlite3.h>
#include "model/x01_model.h"
#include "model/game.h"


int x01_create_game_with_players(sqlite3 *db, int num_players, const X01GameConfig *x01_game_config, const X01PlayerConfig *player_configs, const GameConfig *game_config, int *out_game_id);



#endif // GAME_SERVICE_H