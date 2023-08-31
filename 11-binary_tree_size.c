#include "binary_trees.h"

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
