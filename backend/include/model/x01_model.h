# ifndef X01_MODEL_H
# define X01_MODEL_H



typedef struct {
    int starting_score;
    int double_in;
    int double_out;
} X01GameConfig;

typedef struct {
    int player_id;
    int starting_score_override;
    int double_in_override;
    int double_out_override;
} X01PlayerConfig;

# endif // X01_MODEL_H

