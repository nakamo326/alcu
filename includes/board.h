#ifndef INCLUDES_ALCU
#define INCLUDES_ALCU

// 最後のlineからitemをとる。 -> 先頭に要素を追加する連結リスト
typedef struct s_board {
	struct s_heap*	next;
	int 			items;
} t_board;

#endif /* INCLUDES_ALCU */
