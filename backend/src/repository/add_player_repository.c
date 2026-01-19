#include "sqlite3.h"
#include "repository/add_player_repository.h"
#include "model/player.h"

#include <stdio.h>



int player_create(sqlite3 *db, const char *name, int *out_player_id) {
    if (!db || !name || !out_player_id) {
        return SQLITE_MISUSE;
    }

    const char *sql = "INSERT INTO players (name) VALUES (?);";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to bind name parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    *out_player_id = (int)sqlite3_last_insert_rowid(db);

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}