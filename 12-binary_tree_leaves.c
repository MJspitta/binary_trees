#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to root node of tree to count the number of leaves
 *
 * Return: count of leaves or 0 (NULL)
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t ll, rl, l;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	ll = binary_tree_leaves(tree->left);
	rl = binary_tree_leaves(tree->right);
	l = ll + rl;

	return (l);
}
