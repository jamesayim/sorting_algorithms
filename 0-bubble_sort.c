#include <stdio.h>
#include "sort.h"

/**
 * swap_ints - To swap two integers in an array.
 * @x: It's the first integer to swap.
 * @y: It's the second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - To sort an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: This prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
