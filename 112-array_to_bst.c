#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node of created bst or NULL (failure)
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
