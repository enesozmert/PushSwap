#include "header.h"

void handler(char *name, t_stack **lista, t_stack **listb)
{
	int i;
	t_move move;
	t_move_select move_selects[12];

	i = 0;
	move_selects[0] = (t_move_select){"sa", swap_a};
	move_selects[1] = (t_move_select){"sb", swap_b};
	move_selects[2] = (t_move_select){"ss", swap_ss};
	move_selects[3] = (t_move_select){"pa", push_a};
	move_selects[4] = (t_move_select){"pb", push_b};
	move_selects[5] = (t_move_select){"ra", rotate_a};
	move_selects[6] = (t_move_select){"rb", rotate_b};
	move_selects[7] = (t_move_select){"rr", rotate_rr};
	move_selects[8] = (t_move_select){"rra", rev_rotate_a};
	move_selects[9] = (t_move_select){"rrb", rev_rotate_b};
	move_selects[10] = (t_move_select){"rrr", rev_rotate_rrr};
	move_selects[11] = (t_move_select){NULL, NULL};
	while (move_selects[i].name != NULL)
	{
		if (strncmp(name, move_selects[i].name, strlen(name)) == 0)
		{
			printf("%s\n", move_selects[i].name);
			move.count++;
			move_selects[i].f(lista, listb);
			break ;
		}
		i++;
	}

}