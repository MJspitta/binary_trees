#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts binary max heap to sorted array of ints
 * @heap: pointer to root node of heap to convert
 * @size: address to store the size of array
 *
 * Return: array in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t count, i;
	heap_t *hold;
	int *sorted;

	if (heap == NULL || size == NULL)
		return (NULL);
	count = 0;
	hold = heap;
	while (hold != NULL)
	{
		count++;
		hold = hold->left;
	}
	sorted = malloc(sizeof(int) * count);
	if (sorted == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		sorted[i] = heap->n;
		heap->n = heap->n - 1;
		heapdown(heap);
	}
	*size = count;

	return (sorted);
}
