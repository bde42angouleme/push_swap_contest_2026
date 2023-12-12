/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:46:35 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 19:57:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

/**
 * @brief A stack that holds its top value at index size - 1.
 */
typedef struct s_stack
{
	int			*values;
	size_t		capacity;
	size_t		size;
}	t_stack;

/**
 * @brief Creates a new stack.
 * @param size The size of the stack.
 * @return The new stack.
 */
t_stack	*ps_stack_init(size_t size);

/**
 * @brief Resizes a stack to a new size.
 * @param stack The stack to resize.
 * @param new_size The new size of the stack.
 */
void	ps_stack_resize(t_stack *stack, size_t new_size);

/**
 * @brief Frees a stack.
 * @param stack A pointer to the stack to free.
 */
void	ps_stack_free(t_stack **stack);

/**
 * @brief Prints a stack.
 * @param stack The stack to print.
 */
void	ps_stack_print(t_stack *stack);

/**
 * @brief Prints two stacks next to eachother.
 * @param a The first stack.
 * @param b The second stack.
 */
void	ps_stack_prints(t_stack *a, t_stack *b);

/**
 * @brief Clones a stack into a new one.
 * @param stack The stack to be cloned.
 * @return The new stack.
 */
t_stack	*ps_stack_clone(t_stack *stack);

/* Unrestricted operations (read-only) */

/**
 * @brief Checks if the stack is empty.
 * @param stack The stack to check.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int		ps_stack_is_empty(t_stack *stack);

/**
 * @brief Checks if the stack is sorted.
 * @param stack The stack to check.
 * @return 1 if the stack is sorted, 0 otherwise.
 */
int		ps_stack_is_sorted(t_stack *stack);

/**
 * @brief Returns the value at the top of the stack.
 * @param stack The stack to check.
 * @return The value at the top of the stack.
 * @note The stack must not be empty.
 */
int		ps_stack_top(t_stack *stack);

/**
 * @brief Returns the value at the bottom of the stack.
 * @param stack The stack to check.
 * @return The value at the bottom of the stack.
 * @note The stack must not be empty.
 */
int		ps_stack_bottom(t_stack *stack);

/**
 * @brief Returns the index of the lowest value of the stack.
 * @param stack The stack to check.
 * @return The index of the lowest value of the stack.
 * @note The stack must not be empty.
 */
size_t	ps_stack_min_i(t_stack *stack);

int		ps_stack_min(t_stack *stack);

size_t	ps_stack_max_i(t_stack *stack);

int		ps_stack_max(t_stack *stack);

/**
 * @brief Returns the value at the specified index.
 * @param stack The stack to check.
 * @param index The index of the value to return.
 * @return The value at the specified index.
 */
int		ps_stack_get(t_stack *stack, size_t index);

/**
 * @brief Checks if the stack contains a value.
 * @param stack The stack to check.
 * @param value The value to check for.
 * @return 1 if the stack contains the value, 0 otherwise.
 */
int		ps_stack_contains(t_stack *stack, int value);

/* Restricted operations (read-write) */

/**
 * @brief Pushes a value to the top of the stack.
 * @param stack The stack to push to.
 * @param value The value to push.
 */
void	ps_stack_r_push(t_stack *stack, int value);

/**
 * @brief Pushes a value to the bottom of the stack.
 * @param stack The stack to push to.
 * @param value The value to push.
 */
void	ps_stack_r_insert(t_stack *stack, int value);

/**
 * @brief Pops a value from the top of the stack.
 * @param stack The stack to pop from.
 * @return The value that was popped.
 */
int		ps_stack_r_pop(t_stack *stack);

/**
 * @brief Pops a value from the bottom of the stack.
 * @param stack The stack to pop from.
 * @return The value that was popped.
 */
int		ps_stack_r_remove(t_stack *stack);

/* Public operations (read-write) */

/**
 * @brief Swaps the top two values of the stack.
 * @param stack The stack to swap.
 * @note Does nothing if the stack contains less than two elements.
 */
void	ps_stack_swap(t_stack *stack);

/**
 * @brief Rotates the stack up by one.
 * @param stack The stack to rotate.
 * @note Does nothing if the stack is empty.
 */
void	ps_stack_rotate(t_stack *stack);

/**
 * @brief Rotates the stack down by one.
 * @param stack The stack to rotate.
 * @note Does nothing if the stack is empty.
 */
void	ps_stack_revrotate(t_stack *stack);

/**
 * @brief Pushes a value from the top of this stack to the top 
 * 		  of the other stack.
 * @param stack The stack to push from.
 * @param other The stack to push to.
 * @note Does nothing if the stack is empty.
 */
void	ps_stack_push(t_stack *stack, t_stack *other);

#endif // STACK_H
