#include <unistd.h>

int find_self_doubles(char *str, int i, char c)
{
	int x = 0;
	while (x < i)
	{
		if (str[x] == c)
			return 1;
		x++;
	}
	return 0;
}

int find_other_doubles(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return 0;
		str++;
	}
	return 1;
}

int main (int argc, char **argv)
{
	int i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (find_self_doubles(argv[1], i, argv[1][i]) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (find_self_doubles(argv[2], i, argv[2][i]) == 0)
				if (find_other_doubles(argv[1], argv[2][i]) == 1)
					write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}