#include "sort.h"

void lomuto_sort(int *array, size_t size, int lt, int rt);
void quick_sort(int *array, size_t size);
void swap_ints(int *c, int *d);
int lomuto_partition(int *array, size_t size, int lt, int rt);

/**
 * swap_ints - To swap two integers in an array.
 * @c: This is the first integer to swap.
 * @d: This is the second integer to swap.
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * lomuto_partition - To order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @lt: This is the starting index of the subset to order.
 * @rt: THis is the ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lt, int rt)
{
	int *pivot, above, below;

	pivot = array + rt;
	for (above = below = lt; below < rt; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - To implement the quicksort algorithm through recursion.
 * @array: This is an array of integers to sort.
 * @size: This is the size of the array.
 * @lt: This is the starting index of the array partition to order.
 * @rt: This is the ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int lt, int rt)
{
	int part;

	if (rt - lt > 0)
	{
		part = lomuto_partition(array, size, lt, rt);
		lomuto_sort(array, size, lt, part - 1);
		lomuto_sort(array, size, part + 1, rt);
	}
}

/**
 * quick_sort - This is to sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: This uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
