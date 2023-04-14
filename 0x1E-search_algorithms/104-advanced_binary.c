#include "search_algos.h"

/**
 * rec_search - searches for a value in an array of
 * integer using the Binary search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search
 * Return: the index
 */
int rec_search(int *array, size_t size, int value)
{
	size_t halved = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (halved && size % 2 == 0)
		halved--;

	if (value == array[halved])
	{
		if (halved > 0)
			return (rec_search(array, halved + 1, value));
		return ((int)halved);
	}

	if (value < array[halved])
		return (rec_search(array, halved + 1, value));

	halved++;
	return (rec_search(array + halved, size - halved, value) + halved);
}

/**
 * advanced_binary - calls to rec_search to return
 * index  number
 *
 * @array: input array
 * @size: size of the array
 * @value:search  value
 * Return: index number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = rec_search(array, size, value);

	if (i >= 0 && array[i] != value)
		return (-1);

	return (i);
}
