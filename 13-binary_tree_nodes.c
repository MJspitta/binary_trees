#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in binary tree
 * @tree: pointer to root node of tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child or 0 (NULL)
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		count = 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
		return (count);
	}

	return (0);
}
