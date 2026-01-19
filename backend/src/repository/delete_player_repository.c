#include <stdio.h>
#include "sqlite3.h"
#include "repository/delete_player_repository.h"




int delete_player(sqlite3 *db, int player_id){
    if (!db) {
        return SQLITE_MISUSE;
    }

    const char *sql = "DELETE FROM players WHERE id = ?;";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_bind_int(stmt, 1, player_id);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to bind player_id parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;


}