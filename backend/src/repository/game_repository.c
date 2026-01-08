#include "repository/game_repository.h"

#include <stdio.h>


int game_create(sqlite3 *db, int *game_id) {
    if (db == NULL || game_id == NULL) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);
        return SQLITE_MISUSE;
    }
    


    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO game (status) VALUES ('CREATED');";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return rc;
    }

    *game_id = sqlite3_last_insert_rowid(db);
    sqlite3_finalize(stmt);

    return SQLITE_OK;
}