#include "monty.h"

char *argument = NULL;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		opcode = strtok(line, " \n\t");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		argument = strtok(NULL, " \n\t");

		execute_opcode(opcode, &stack, line_number);
	}

	fclose(file);

	free_stack(stack);

	return (0);
}
