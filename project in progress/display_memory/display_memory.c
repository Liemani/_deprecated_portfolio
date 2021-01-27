#include <stdio.h>

int transform(char ch)
{
	if (32 <= ch && ch <= 127)
		return (ch);
	return (' ');
}

int main(int argc, char **argv)
{
	if (argc !=2)
	{
		printf("argc must 2 \n");
		return (0);
	}

	const char	*seperator = "                    +---------+";
	char		*cur_char;

	cur_char = *(argv + 1);
	while (*cur_char)
		++cur_char;
	printf("%s \n", seperator);
	printf("%16p -> | %3d [%c] | \n", cur_char, *cur_char, transform(*cur_char));
	printf("%s \n", seperator);
	while (cur_char != *(argv + 1))
	{
		--cur_char;
		printf("%16p -> | %3d [%c] | \n", cur_char, *cur_char, transform(*cur_char));
		printf("%s \n", seperator);
	}

	return (0);
}
