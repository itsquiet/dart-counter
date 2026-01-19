#include "model/player.h"
#include "service/delete_player_service.h"
#include "db/database.h"
#include <stdio.h>

int delete_player_service(sqlite3 *db, int player_id) {
    if (!db) {
        return SQLITE_MISUSE;
    }

    int rc = start_transaction(db);
    if (rc != SQLITE_OK) {
        return rc;
    }

    rc = player_delete(db, player_id);
    if (rc != SQLITE_OK) {
        rollback_transaction(db);
        return rc;
    }

    rc = commit_transaction(db);
    if (rc != SQLITE_OK) {
        return rc;
    }

    return SQLITE_OK;
}