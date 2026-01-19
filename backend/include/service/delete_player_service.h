#ifndef DELETE_PLAYER_SERVICE_H
#define DELETE_PLAYER_SERVICE_H
#include <sqlite3.h>

int delete_player_service(sqlite3 *db, int player_id);

#endif // DELETE_PLAYER_SERVICE_H