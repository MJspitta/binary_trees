#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - check if tree is a valid binary search tree
 * @tree: pointer to root node of tree to check
 * @min_val: value of smallest node visited thus far
 * @max_val: value of largest node visited thus far
 *
 * Return: 1 (tree is valid) or 0
 */
int bst_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min_val || tree->n >= max_val)
		return (0);

	return (bst_helper(tree->left, min_val, tree->n) &&
			bst_helper(tree->right, tree->n, max_val));
}

/**
 * binary_tree_is_bst - checks if binary tree is a valid binary search tree
 * @tree: pointer to root node of the tree to check
 *
 * Return: 1 (tree is valid) or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}
