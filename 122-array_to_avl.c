#include "binary_trees.h"

/**
 * array_to_avl - bilds an avl tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to root node of created avl tree or NULL (failure)
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
