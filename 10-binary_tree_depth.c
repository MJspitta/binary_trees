#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of node in a binary tree
 * @tree: pointer to node to measure the depth
 *
 * Return: depth or 0 (NULL)
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);

	d = 0;
	while (tree->parent != NULL)
	{
		d++;
		tree = tree->parent;
	}

	return (d);
}
