#ifndef X01_GAME_CONFIG_REPOSITORY_H
#define X01_GAME_CONFIG_REPOSITORY_H

#include <sqlite3.h>

int x01_game_config_create(sqlite3 *db, int game_id, int starting_score, int double_in, int double_out);

#endif // X01_GAME_CONFIG_REPOSITORY_H