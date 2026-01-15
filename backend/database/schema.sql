PRAGMA foreign_keys = ON;

-- =========================
-- Spiel
-- =========================
CREATE TABLE game (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    --Metadaten
    created_at    TEXT NOT NULL DEFAULT (datetime('now')),
    status        TEXT NOT NULL CHECK (status IN ('CREATED', 'RUNNING', 'FINISHED')),

    --Spieltyp
    game_mode    INTEGER,
    legs_to_win  INTEGER,
    sets_to_win  INTEGER

);

-- =========================
-- Spieler
-- =========================
CREATE TABLE player (
    id      INTEGER PRIMARY KEY AUTOINCREMENT,
    name    TEXT NOT NULL,
    created_at TEXT NOT NULL DEFAULT (datetime('now'))

);

-- =========================
-- Zuordnung Spieler <-> Spiel
-- =========================
CREATE TABLE game_player (
    game_id       INTEGER NOT NULL,
    player_id     INTEGER NOT NULL,
    play_order    INTEGER NOT NULL,

    PRIMARY KEY (game_id, player_id),
    FOREIGN KEY (game_id)   REFERENCES game(id)   ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES player(id) ON DELETE CASCADE
);

-- =========================
-- Events (jeder Wurf)
-- =========================
CREATE TABLE game_event (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    game_id       INTEGER NOT NULL,
    player_id     INTEGER NOT NULL,

    turn_number   INTEGER NOT NULL,
    throw_number  INTEGER NOT NULL CHECK (throw_number BETWEEN 1 AND 3),

    field_value   INTEGER NOT NULL CHECK (field_value BETWEEN 1 AND 20 OR field_value = 25),
    multiplier    INTEGER NOT NULL CHECK (multiplier IN (1, 2, 3)),
    points        INTEGER NOT NULL CHECK (points BETWEEN 0 AND 180),

    created_at    TEXT NOT NULL DEFAULT (datetime('now')),

    FOREIGN KEY (game_id)   REFERENCES game(id)   ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES player(id) ON DELETE CASCADE
);


-- =========================
-- X01 Game Configuration
-- =========================
CREATE TABLE x01_game_config (
    game_id          INTEGER PRIMARY KEY,
    starting_score   INTEGER NOT NULL,
    double_in        BOOLEAN NOT NULL,
    double_out       BOOLEAN NOT NULL,

    FOREIGN KEY (game_id) REFERENCES game(id) ON DELETE CASCADE
);


CREATE TABLE x01_game_player_config(
    game_id INTEGER NOT NULL,
    player_id INTEGER NOT NULL,


    starting_score_override INTEGER,
    double_in_override BOOLEAN,
    double_out_override BOOLEAN,

    PRIMARY KEY (game_id, player_id),
    FOREIGN KEY (game_id) REFERENCES game(id) ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES player(id) ON DELETE CASCADE
);

-- =========================
-- Performance / Rekonstruktion
-- =========================
CREATE INDEX idx_event_game ON game_event(game_id);
CREATE INDEX idx_event_player ON game_event(player_id);
CREATE INDEX idx_event_turn ON game_event(game_id, turn_number);
