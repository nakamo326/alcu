#include "alcu.h"
#include "libft.h"

void	print_map(t_data *ds)
{
	for (int i = 0; ds->map[i] != 0; i++)
	{
		for (int j = 0; j < ds->map[i]; j++)
		{
			ft_putstr_fd("| ", STDOUT_FILENO);
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
}
