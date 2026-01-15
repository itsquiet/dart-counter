#include "service/x01_game_service.h"
#include "model/game.h"
#include "model/x01_model.h"
#include "db/database.h"
#include "repository/game_repository.h"
#include "repository/game_player_repository.h"

#include <stdio.h>


int x01_create_game_with_players(sqlite3 *db, int num_players, const X01GameConfig *x01_game_config, const X01PlayerConfig *player_configs, const GameConfig *game_config, int *out_game_id) {

    if (!db || !x01_game_config || !player_configs || !game_config || !out_game_id || num_players <= 0) {
    return SQLITE_MISUSE;
    }



    int rc = start_transaction(db);
    if (rc != SQLITE_OK) {
        return rc;
    }

    int game_id;
    

    rc = game_create(db, &game_id, game_config->game_mode, game_config->legs_to_win, game_config->sets_to_win);
    if (rc != SQLITE_OK) {
        rollback_transaction(db);
        return rc;
    }

    for (int i = 0; i < num_players; i++) {
        rc = game_player_add(db, game_id, player_configs[i].player_id, i+1);
        if (rc != SQLITE_OK) {
            rollback_transaction(db);
            return rc;
        }
    }

    // Create X01 game configuration

    rc = x01_game_config_create(db, game_id, x01_game_config->starting_score, x01_game_config->double_in, x01_game_config->double_out);
    if (rc != SQLITE_OK) {
        rollback_transaction(db);
        return rc;
    }

    // Create X01 player configurations
    for( int i = 0; i < num_players; i++) {
        rc = x01_game_player_config_create(db, game_id, player_configs[i].player_id, player_configs[i].starting_score_override, player_configs[i].double_in_override, player_configs[i].double_out_override);
        if (rc != SQLITE_OK) {
            rollback_transaction(db);
            return rc;
        }
    }

    rc = commit_transaction(db);


    *out_game_id = game_id;
    return SQLITE_OK;
}