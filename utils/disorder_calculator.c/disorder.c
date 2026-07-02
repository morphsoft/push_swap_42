#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		mistakes;
	int		ii;
	int		jj;

	size = ft_stack_size(stack_a);
	if (size < 2)
		return (0.0f);           /* guard: total_pairs would be 0 */
	mistakes = 0;
	a = stack_a;
	ii = 0;
	while (ii < size - 1)
	{
		b = a->next;
		jj = ii + 1;
		while (jj < size)
		{
			if (a->value > b->value)
				mistakes++;
			b = b->next;
			jj++;
		}
		a = a->next;
		ii++;
	}
	return ((float)mistakes / (size * (size - 1) / 2));
}
