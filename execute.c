#include "monty.h"

/**
 * execute_opcode - executes opcode
 * @opcode: opcode
 * @stack: stack
 * @line_number: current line
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
        push(stack, line_number);
    else if (strcmp(opcode, "pall") == 0)
        pall(stack, line_number);
    else if (strcmp(opcode, "pint") == 0)
        pint(stack, line_number);
    else if (strcmp(opcode, "pop") == 0)
        pop_op(stack, line_number);
    else if (strcmp(opcode, "swap") == 0)
        swap(stack, line_number);
    else if (strcmp(opcode, "add") == 0)
        add(stack, line_number);
    else if (strcmp(opcode, "nop") == 0)
        nop(stack, line_number);
    else if (strcmp(opcode, "sub") == 0)
        sub(stack, line_number); 
    else if (strcmp(opcode, "div") == 0)
        div_op(stack, line_number);
    else if (strcmp(opcode, "mul") == 0)
        mul(stack, line_number);
    else if (strcmp(opcode, "mod") == 0)
        mod_op(stack, line_number);
    else if (strcmp(opcode, "pchar") == 0)
        pchar(stack, line_number);
    else if (strcmp(opcode, "pstr") == 0)
        pstr(stack, line_number);
    else if (strcmp(opcode, "rotl") == 0)
        rotl(stack, line_number);
    else if (strcmp(opcode, "rotr") == 0)
        rotr(stack, line_number);
    else if (strcmp(opcode, "stack") == 0)
        stack_mode(stack, line_number);
else if (strcmp(opcode, "queue") == 0)
        queue_mode(stack, line_number);
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
