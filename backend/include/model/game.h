#ifndef GAME_H
#define GAME_H


typedef enum {
    x01 = 1,
    cricket = 2
} GameMode;

typedef struct{
    GameMode game_mode;
    int legs_to_win;
    int sets_to_win;
}GameConfig;

#endif // GAME_H