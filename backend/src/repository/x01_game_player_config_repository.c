#include "repository/x01_game_player_config_repository.h"
#include <sqlite3.h>
#include <stdio.h>

int x01_game_player_config_create(sqlite3 *db, int game_id, int player_id, int starting_score_override, int double_in_override, int double_out_override) {
    if (db == NULL || game_id <= 0 || player_id <= 0) {
        fprintf(stderr, "[DB] misuse: database handle is NULL or invalid IDs in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO x01_game_player_config (game_id, player_id, starting_score_override, double_in_override, double_out_override) VALUES (?, ?, ?, ?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] prepare failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        return rc;
    }


    

    rc = sqlite3_bind_int(stmt, 1, game_id);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }
    rc = sqlite3_bind_int(stmt, 2, player_id);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    if (starting_score_override < 0) {
            rc = sqlite3_bind_null(stmt, 3);
        } 
        else {
            rc = sqlite3_bind_int(stmt, 3, starting_score_override);
        }

    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }
    

    if (double_in_override < 0) {
            rc = sqlite3_bind_null(stmt, 4);
        } 
        else {
            rc = sqlite3_bind_int(stmt, 4, double_in_override);
        }

    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    if (double_out_override < 0) {
            rc = sqlite3_bind_null(stmt, 5);
        } 
        else {
            rc = sqlite3_bind_int(stmt, 5, double_out_override);
        }

    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return rc;
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}