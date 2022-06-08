#include "header.h"

int *number_to_digits(int n)
{
	int *arr;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * 3);
	while (n > 0)
	{
		arr[2 - i] = n % 10;
		n /= 10;
		i++;
	}
	return (arr);
}