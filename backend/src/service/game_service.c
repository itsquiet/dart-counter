#include "service/game_service.h"
#include "db/database.h"
#include "repository/game_repository.h"
#include "repository/game_player_repository.h"
#include <stdio.h>


int create_game_with_players(sqlite3 *db, const int *player_ids, int num_players, int *out_game_id){
    if (db == NULL || player_ids == NULL || num_players <= 0 || out_game_id == NULL) {
        fprintf(stderr, "[DB] misuse: invalid arguments in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    int rc = start_transaction(db);
    if (rc != SQLITE_OK) {
        return rc;
    }

    int game_id;
    rc = game_create(db, &game_id);
    if (rc != SQLITE_OK) {
        rollback_transaction(db);
        return rc;
    }

    for (int i = 1; i < num_players; i++) {
        rc = game_player_add(db, game_id, player_ids[i], i, 0);
        if (rc != SQLITE_OK) {
            rollback_transaction(db);
            return rc;
        }
    }

    rc = commit_transaction(db);
    if (rc != SQLITE_OK) {
        rollback_transaction(db);
        return rc;
    }

    *out_game_id = game_id;
    return SQLITE_OK;
}