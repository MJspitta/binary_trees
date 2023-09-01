#include "binary_trees.h"

/**
 * heap_height - get height
 * @node: node
 *
 * Return: height
 */
int heap_height(heap_t *node)
{
	if (node == NULL)
		return (0);

	return (1 + heap_height(node->left));
}

/**
 * heap_extract - extracts root node of a max binary heap
 * @root: double pointer to root node of heap
 *
 * Return: value stored in root node or 0 (fails)
 */
int heap_extract(heap_t **root)
{
	int val, h;
	heap_t *last;

	if (root == NULL || *root == NULL)
		return (0);
	val = (*root)->n;
	last = *root;
	h = heap_height(*root);
	while (last->left != NULL || last->right != NULL)
	{
		if (last->right != NULL && heap_height(last->right) == h - 1)
			last = last->right;
		else
			last = last->left;
		h--;
	}
	(*root)->n = last->n;
	if (last->parent != NULL)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		free(last);
	}
	else
	{
		free(*root);
		*root = NULL;
	}
	if (*root != NULL)
		heapdown(*root);

	return (val);
}
