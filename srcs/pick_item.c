#include "alcu.h"

void	pick_items(t_data *ds, int pick)
{
	debug_print(ds);
	int i = ds->index;
	if (ds->map[i] >= pick) {
		ds->map[i] -= pick;
	} else {
		ds->map[i] = 0;
	}
	if (ds->index != 0 && ds->map[i] == 0)
		ds->index--;
}
