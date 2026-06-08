#include "monty.h"

/**
 * execute_opcode - executes opcode
 * @opcode: opcode
 * @stack: stack
 * @line_number: current line
 */
void execute_opcode(char *opcode, stack_t **stack,
	unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (strcmp(opcode, "push") == 0)
		printf("PUSH FOUND\n");
	else if (strcmp(opcode, "pall") == 0)
		printf("PALL FOUND\n");
	else
	{
		fprintf(stderr,
			"L%u: unknown instruction %s\n",
			line_number,
			opcode);
		exit(EXIT_FAILURE);
	}
}
