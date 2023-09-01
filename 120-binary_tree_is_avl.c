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
 * avl_helper - checks if binary tree is a valid avl tree
 * @tree: pointer to root node of tree to check
 * @h: height
 *
 * Return: 1 (tree is valid) or 0
 */
int avl_helper(const binary_tree_t *tree, int *h)
{
	int lh, rh, avl_left, avl_right;

	if (tree == NULL)
	{
		*h = 0;
		return (1);
	}

	lh = rh = 0;
	avl_left = avl_helper(tree->left, &lh);
	avl_right = avl_helper(tree->right, &rh);
	if (lh > rh)
		*h = lh + 1;
	else
		*h = rh + 1;

	if (abs(lh - rh) <= 1 && avl_left && avl_right)
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - checks if binary tree is a valid avl tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 (tree is valid) or 0 (NULL)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h;

	if (tree == NULL)
		return (0);

	h = 0;

	return (avl_helper(tree, &h));
}
