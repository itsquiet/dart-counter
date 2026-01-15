CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lsqlite3

SRC = \
  src/db/sqlite.c \
  src/repository/game_repository.c \
  src/repository/game_player_repository.c \
  src/repository/x01_game_config_repository.c \
  src/repository/x01_game_player_config_repository.c \
  src/service/x01_game_service.c

TEST_SRC = tests/test_create_game.c

test_create_game: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f test_create_game
