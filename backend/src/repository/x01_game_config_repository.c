#include "repository/x01_game_config_repository.h"
#include <sqlite3.h>
#include <stdio.h>


int x01_game_config_create(sqlite3 *db, int game_id, int starting_score, int double_in, int double_out) {
    if (db == NULL || game_id <= 0) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO x01_game_config (game_id, starting_score, double_in, double_out) VALUES (?, ?, ?, ?);";

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

    rc = sqlite3_bind_int(stmt, 2, starting_score);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 3, double_in);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] bind failed in %s: %s\n", __func__, sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 4, double_out);
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