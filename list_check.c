#include "header.h"

void	ft_exit(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void	check_double(char **argv, int i, int j)
{
	char	*dup;

	while (argv[++i])
	{
		dup = ft_strdup(argv[i]);
		j = 0;
		while (argv[j])
		{
			if (i == j)
				j++;
			else if (ft_strncmp(dup, argv[j], ft_strlen(dup)) == 0)
			{
				free(dup);
				dup = NULL;
				ft_exit("Error\n");
			}
			else
				j++;
		}
	}
	free(dup);
	dup = NULL;
}

static int	check_overflow(char *s)
{
	long long	n;

	n = ft_atoi(s);
	if (n <= INT_MAX && n >= INT_MIN)
		return (1);
	return (0);
}

void	check_number(char **s, int i, int j)
{
	while (s[++i])
	{
		j = -1;
		if (!check_overflow(s[i]))
			ft_exit("Error\n");
		while (s[i][++j])
		{
			if (ft_isalpha(s[i][j]) || s[i][j] == '.' ||
				(s[i][j] == '-' && s[i][j + 1] == '\0') ||
				(s[i][j] == '+' && s[i][j + 1] == '\0'))
				ft_exit("Error\n");
		}
	}
}

char	**fill_args(int ac, char **av)
{
	char **argv;

	argv = (char **)malloc(sizeof(char *) * ac);
	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
		argv = &av[1];
	return (argv);
}