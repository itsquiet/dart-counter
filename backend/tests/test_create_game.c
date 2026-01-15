#include <stdio.h>
#include <sqlite3.h>

#include "db/database.h"
#include "service/x01_game_service.h"
#include "model/game.h"
#include "model/x01_model.h"


int main(void) {
    sqlite3 *db = NULL;

    int rc = db_open("database/test.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open DB\n");
        return 1;
    }

    X01PlayerConfig players[2] = {
        {
            .player_id = 1,
            .starting_score_override = -1,
            .double_in_override = -1,
            .double_out_override = -1
        },
        {
            .player_id = 2,
            .starting_score_override = 301,
            .double_in_override = -1,
            .double_out_override = 1
        }
    };

    int num_players = 2;

        X01GameConfig x01_config = {
        .starting_score = 501,
        .double_in = 0,
        .double_out = 1
    };

        GameConfig game_config = {
        .game_mode = x01,
        .legs_to_win = 3,
        .sets_to_win = 1
    };

        int game_id = -1;

    rc = x01_create_game_with_players(
        db,
        num_players,
        &x01_config,
        players,
        &game_config,
        &game_id
    );

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Game creation failed: %d\n", rc);
        db_close(db);
        return 1;
    }

    printf("Game successfully created with ID: %d\n", game_id);

    db_close(db);
    return 0;
}