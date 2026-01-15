#ifndef DATABASE_H
#define DATABASE_H
#include <sqlite3.h>

int start_transaction(sqlite3 *db);
int commit_transaction(sqlite3 *db);
int rollback_transaction(sqlite3 *db);

int db_open(const char *path, sqlite3 **db);
void db_close(sqlite3 *db);

#endif // DATABASE_H


