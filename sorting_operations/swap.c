void swap(t_stack stack, int swap_type, int **operations)
{
	ft_swap(&stack->value, &stack->next->value);
	operations[swap_type] += 1;
}
