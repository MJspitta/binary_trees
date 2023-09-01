#include "binary_trees.h"

/**
 * createavl - create avl tree
 * @array: array to create from
 * @start: start of array
 * @end: end of array
 *
 * Return: root or NULL
 */
avl_t *createavl(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = createavl(array, start, mid - 1);
	root->right = createavl(array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - builds an avl tree from an array
 * @array: pointer to the first element of the arrary to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node of created avl tree or NULL (failure)
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (createavl(array, 0, size - 1));
}
