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
    game_type     TEXT NOT NULL CHECK (game_type IN ('X01', 'CRICKET')),

    --Globale Standartregeln
    default_start_score INTEGER,
    default_out_rule TEXT CHECK (default_out_rule IN ('STRAIGHT', 'DOUBLE')),
    default_in_rule  TEXT CHECK (default_in_rule  IN ('STRAIGHT', 'DOUBLE')),
    default_legs_to_win INTEGER,
    default_sets_to_win INTEGER

    --Zukunft Modi Settings


);

-- =========================
-- Spieler
-- =========================
CREATE TABLE player (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    name          TEXT NOT NULL
);

-- =========================
-- Zuordnung Spieler <-> Spiel
-- =========================
CREATE TABLE game_player (
    game_id       INTEGER NOT NULL,
    player_id     INTEGER NOT NULL,
    play_order    INTEGER NOT NULL,
    start_score   INTEGER NOT NULL DEFAULT 501,

    PRIMARY KEY (game_id, player_id),
    FOREIGN KEY (game_id)  REFERENCES game(id)   ON DELETE CASCADE,
    FOREIGN KEY (player_id)REFERENCES player(id) ON DELETE CASCADE
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
    points        INTEGER NOT NULL CHECK (points BETWEEN 0 AND 180),
    created_at    TEXT NOT NULL DEFAULT (datetime('now')),

    FOREIGN KEY (game_id)   REFERENCES game(id)   ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES player(id) ON DELETE CASCADE
);

-- =========================
-- Performance / Rekonstruktion
-- =========================
CREATE INDEX idx_event_game ON game_event(game_id);
CREATE INDEX idx_event_player ON game_event(player_id);
CREATE INDEX idx_event_turn ON game_event(game_id, turn_number);
