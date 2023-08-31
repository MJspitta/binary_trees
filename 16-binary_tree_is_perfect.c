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
 * binary_tree_size - measure size of binary tree
 * @tree: pointer to root node of tree to measure the size
 *
 * Return: size or 0 (NULL)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t ls, rs, s;

	if (tree == NULL)
		return (0);

	ls = binary_tree_size(tree->left);
	rs = binary_tree_size(tree->right);
	s = ls + rs + 1;

	return (s);
}

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 (is perfect) or 0 (NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, s;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);
	s = binary_tree_size(tree);

	return (s == ((size_t)1 << h) - 1);
}
