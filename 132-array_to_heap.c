#include "binary_trees.h"

/**
 * heapdown - builds a max binary heap tree
 * @node: node
 *
 * Return: nothing
 */
void heapdown(heap_t *node)
{
	heap_t *large;
	int hold;

	if (node == NULL)
		return;
	large = node;
	if (node->left != NULL && node->left->n > large->n)
		large = node->left;
	if (node->right != NULL && node->right->n > large->n)
		large = node->right;
	if (large != node)
	{
		hold = node->n;
		node->n = large->n;
		large->n = hold;
		heapdown(large);
	}
}

/**
 * array_to_heap - builds a max binary heap tree from array
 * @array: pointer to the first element of array to be converted
 * @size: number of elements in array
 *
 * Return: pointer to root node of created binary heap or NULL (failure)
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root, *new, *curr;
	size_t i;
	int hold;

	if (array == NULL || size == 0)
		return (NULL);
	root = binary_tree_node(NULL, array[0]);
	if (root == NULL)
		return (NULL);
	for (i = 1; i < size; i++)
	{
		new = binary_tree_node(root, array[i]);
		if (new == NULL)
			return (NULL);
		curr = new->parent;
		while (curr != NULL && curr->n < new->n)
		{
			hold = curr->n;
			curr->n = new->n;
			new->n = hold;
			new = curr;
			curr = curr->parent;
		}
	}

	return (root);
}
