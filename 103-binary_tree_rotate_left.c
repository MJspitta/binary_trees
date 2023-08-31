#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on binary tree
 * @tree: pointer to root node of tree to rotate
 *
 * Return: pointer to new root node of tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	newroot = tree->right;
	tree->right = newroot->left;
	if (newroot->left != NULL)
		newroot->left->parent = tree;

	newroot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = newroot;
		else
			tree->parent->right = newroot;
	}

	newroot->left = tree;
	tree->parent = newroot;

	return (newroot);
}
