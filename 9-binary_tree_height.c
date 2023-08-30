#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of binary tree
 * @tree: pointer to root node of tree to measure height
 *
 * Return: height or 0 (NULL)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh, h;

	if (tree == NULL)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	if (lh > rh)
		h = lh + 1;
	else
		h = rh + 1;

	return (h);
}
