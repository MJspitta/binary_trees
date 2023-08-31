#include "binary_trees.h"

/**
 * bst_search - searches for a value in binary search tree
 * @tree: pointer to root node of bst to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
