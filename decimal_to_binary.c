#include "header.h"

int *decimal_to_binary(int n)
{
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
	arr = (int *)malloc(sizeof(int) * 9);
	while (bin > 0)
	{
		arr[8 - i] = bin % 10;
		bin /= 10;
		i++;
	}
	return (arr);
}