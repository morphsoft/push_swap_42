# include "push_swap_utils.h"

void	simple_sort(t_stack stack_a, unsigned char flags, double disorder)
{
	int		op_count[8];
	char	**ops;


	cocktail_sort(&stack_a, &op_count, &ops);
	if (flags & FLAG_BENCHMARK)
		create_benchmark("simple / 0(n2)", op_count, ops, disorder);
	else
		ft_printf("%s\n", ops);
}

// Um pouquinho mais eficiente que o bubble, o cocktail é bem maneiro
// Ele basicamente faz a mesma coisa que o bubble
// só que mexe pra direita ou pra esquerda em vez de ser linear
void	cocktail_sort(t_stack *stk, int **op_count, char ***ops)
{
	int	left;
	int	right;
	int	i;
	int	size;

	size = ft_lstsize(stk);
	left = 0;
	right = size - 1;
	while (left < right)
	{
		i = left - 1;
		while (++i < right)
		{
			apply_swap(stk, op_count, ops);
			apply_rotate(stk, op_count, ops);
		}
		right--;
		i = right - 1;
		while (--i > left)
		{
			apply_reverse_rotate(stk, op_count, ops);
			apply_swap(stk, op_count, ops);
		}
		left++;
	}
}

void	apply_swap(t_stack **stack, int **op_count, char ***ops)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		ft_swap(stack, SWAP_A);
		*ops = ft_strjoin(*ops, " sa");
		*op_count[SWAP_A] += 1;
	}
}

void	apply_rotate(t_stack **stk, int **op_count, char ***ops)
{
	ft_rotate(stk, ROTATE_A);
	*ops = ft_strjoin(*ops, " ra");
	*op_count[ROTATE_A] += 1;
}

void	apply_reverse_rotate(t_stack **stk, int **op_count, char ***ops)
{
	ft_reverse_rotate(stk, REVERSE_ROTATE_A);
	*ops = ft_strjoin(*ops, " rra");
	*op_count[REVERSE_ROTATE_A] += 1;
}
