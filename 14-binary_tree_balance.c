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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	if (lh > rh)
		h = lh + 1;
	else
		h = rh + 1;

	return (h);
}

/**
 * binary_tree_balance - measures balance factor of binary tree
 * @tree: pointer to root node of tree to measure balance factor
 *
 * Return: balance factor ro 0 (NULL)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	if (tree->left)
		lh = binary_tree_height(tree->left) + 1;
	else
		lh = 0;

	if (tree->right)
		rh = binary_tree_height(tree->right) + 1;
	else
		rh = 0;

	return (lh - rh);
}
