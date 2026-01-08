#include "db/database.h"
#include <stdio.h>


int start_transaction(sqlite3 *db) {
    if (db == NULL) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);

        return SQLITE_MISUSE;
    }

    char *err_msg = NULL;
    int rc = sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    return rc;
}

int commit_transaction(sqlite3 *db) {
    if (db == NULL) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    char *err_msg = NULL;
    int rc = sqlite3_exec(db, "COMMIT;", NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    return rc;
}

int rollback_transaction(sqlite3 *db) {
    if (db == NULL) {
        fprintf(stderr, "[DB] misuse: database handle is NULL in %s\n", __func__);
        return SQLITE_MISUSE;
    }

    char *err_msg = NULL;
    int rc = sqlite3_exec(db, "ROLLBACK;", NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    return rc;
}