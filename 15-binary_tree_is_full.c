#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to the root node of tree to check
 *
 * Return: 1 (is full) or 0 (NULL)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int fl, fr;

	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
	{
		fl = binary_tree_is_full(tree->left);
		fr = binary_tree_is_full(tree->right);
		return (fl && fr);
	}

	return (0);
}
