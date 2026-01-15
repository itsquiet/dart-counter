#ifndef X01_GAME_PLAYER_CONFIG_REPOSITORY_H
#define X01_GAME_PLAYER_CONFIG_REPOSITORY_H
#include <sqlite3.h>

int x01_game_player_config_create(sqlite3 *db, int game_id, int player_id, int starting_score_override, int double_in_override, int double_out_override);

#endif // X01_GAME_PLAYER_CONFIG_REPOSITORY_H