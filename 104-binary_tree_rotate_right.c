#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on binary tree
 * @tree: pointer to root node of tree to rotate
 *
 * Return: pointer to new root node of tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	newroot = tree->left;
	tree->left = newroot->right;
	if (newroot->right != NULL)
		newroot->right->parent = tree;

	newroot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = newroot;
		else
			tree->parent->right = newroot;
	}

	newroot->right = tree;
	tree->parent = newroot;

	return (newroot);
}
