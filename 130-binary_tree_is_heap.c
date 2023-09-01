#include "binary_trees.h"

/**
 * isheap - checks if is heap
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 (valid) or 0
 */
int isheap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (isheap(tree->left) && isheap(tree->right));
}

/**
 * binary_tree_is_heap - checks if binary tree is valid max binary heap
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 (is valid) or 0 (NULL)
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isheap(tree));
}
