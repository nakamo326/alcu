#include "alcu.h"
#include "libft.h"

void	print_map(t_game *game)
{
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		for (int j = 0; j < game->heap[i].num; j++)
		{
			ft_putstr_fd("| ", STDOUT_FILENO);
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
}
