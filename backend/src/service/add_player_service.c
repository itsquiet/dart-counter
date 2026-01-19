#include "sqlite3.h"
#include "service/add_player_service.h"
#include "model/player.h"
#include "db/database.h"

#include <stdio.h>


int add_player_service(sqlite3 *db, const char *name, int *out_player_id) {
    if (!db || !name || !out_player_id) {
        return SQLITE_MISUSE;
    }

    int rc = start_transaction(db);
    if (rc != SQLITE_OK) {
        return rc;
    }

    rc = player_create(db, name, out_player_id);
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