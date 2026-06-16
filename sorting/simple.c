void	simple_sort(t_stack stack , unsigned char flags, double disorder)
{
	t_stack	stack_b;
	char	*operations;
	int		operation_count[8];

	create_stack(stack_b);
	
	... SORT

	if (flags & FLAG_BENCHMARK)
		create_benchmark("simple / 0(n2)", operation_count, operations, disorder);
	else
		ft_printf("%s\n", operations);
}
