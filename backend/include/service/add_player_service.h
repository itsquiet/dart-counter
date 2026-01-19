#ifndef ADD_PLAYER_SERVICE_H
#define ADD_PLAYER_SERVICE_H

#include <sqlite3.h>
int add_player_service(sqlite3 *db, const char *name, int *out_player_id);

#endif // ADD_PLAYER_SERVICE_H