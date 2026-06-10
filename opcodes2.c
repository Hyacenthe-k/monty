#include "monty.h"

/**
 * pint - prints top element
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - removes top element
 * @stack: stack
 * @line_number: line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL)
        {
                fprintf(stderr,
                        "L%u: can't pop an empty stack\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        temp = *stack;
        *stack = (*stack)->next;

        if (*stack)
                (*stack)->prev = NULL;

        free(temp);
}

/**
 * swap - swaps top two elements
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
        int temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't swap, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
}

/**
 * add - adds top two elements
 * @stack: stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
        int sum;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't add, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        sum = (*stack)->n + (*stack)->next->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = sum;

        free(temp);
}

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div_op - divides second top by top
 * @stack: stack
 * @line_number: line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
        int result;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't div, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n == 0)
        {
                fprintf(stderr,
                        "L%u: division by zero\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        result = (*stack)->next->n / (*stack)->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = result;

        free(temp);
}

/**
 * mul - multiplies top two elements
 * @stack: stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
        int result;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't mul, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        result = (*stack)->n * (*stack)->next->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = result;

        free(temp);
}

/**
 * sub - subtracts the top element from the second top element
 * @stack: stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n - (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->n = result;

    free(temp);
}
