#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> /*gives access to use ssize_t types*/
#include <string.h> /*gives access to use strtok*/

/**
 * main - RSA Factoring Challenge.
 * @argc: Arguement count.
 * @argv: Arguement array.
 * Return: 0 on EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	char *end_ptr;
	int base;
	size_t len = 0;
	ssize_t nread;
	unsigned long long num;
	unsigned long long test_num;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	base = 10;

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error! Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		num = strtoull(strtok(line, "\n"), &end_ptr, base);
		if (num == 1)
		{
			printf("%lld=%lld*%lld\n", num, num, num);
			continue;
		}
		test_num = 2;
		while (num > 0 && test_num != num &&
				(num % test_num) != 0)
			test_num++;
		printf("%lld=%lld*%lld\n", num, num / test_num, test_num);
	}
	fclose(stream);
	free(line);
	return (EXIT_SUCCESS);
}
