#include "header.h"

int	ft_count_digits_llud(long long value, int base)
{
	int	result;

	result = 0;
	if (value == 0)
		return (1);
	if (value <= 0)
	{
		result ++;
		value = -value;
	}
	while (value != 0)
	{
		value /= base;
		result++;
	}
	return (result);
}

int *decimal_to_binary(int n)
{
	int count_digits;
	int *arr;
	long long bin;
	int rem;
	int i;

	bin = 0;
	rem = 1;
	i = 1;
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	i = 0;
	count_digits = ft_count_digits_llud(bin, 2);
	arr = (int *)malloc(sizeof(int) * 9);
	while (bin > 0)
	{
		arr[8 - i] = bin % 10;
		bin /= 10;
		i++;
	}
	return (arr);
}