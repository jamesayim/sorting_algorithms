#include "sort.h"

/**
 * swap_ints - This is to swap two integers in an array.
 * @c: It is the first integer to swap.
 * @d: It is the second integer to swap.
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * selection_sort - This is to sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: This is to prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (y = x + 1; y < size; y++)
			min = (array[y] < *min) ? (array + y) : min;

		if ((array + x) != min)
		{
			swap_ints(array + x, min);
			print_array(array, size);
		}
	}
}
