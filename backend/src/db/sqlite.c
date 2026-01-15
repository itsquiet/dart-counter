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



int db_open(const char *path, sqlite3 **db) {
    int rc = sqlite3_open(path, db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] open failed: %s\n", sqlite3_errmsg(*db));
        return rc;
    }

    // Enable foreign keys
    rc = sqlite3_exec(*db, "PRAGMA foreign_keys = ON;", NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "[DB] PRAGMA foreign_keys failed\n");
        sqlite3_close(*db);
        return rc;
    }

    return SQLITE_OK;
}

void db_close(sqlite3 *db) {
    if (db) {
        sqlite3_close(db);
    }
}
