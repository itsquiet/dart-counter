#include "repository/game_player_repository.h"
#include <sqlite3.h>

#include <stdio.h>


int game_player_add(sqlite3 *db, int game_id, int player_id, int play_order) {
    if (db == NULL || game_id <= 0 || player_id <= 0) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO game_player (game_id, player_id, play_order) VALUES (?, ?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] prepare failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 1, game_id);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 2, player_id);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 3, play_order);
    if(rc != SQLITE_OK) {
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