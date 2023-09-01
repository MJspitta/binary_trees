#include "binary_trees.h"

/**
 * binarytree_balance - measures balance factor of binary tree
 * @tree: pointer to root node of tree to measure balance factor
 *
 * Return: balance factor ro 0 (NULL)
 */
int binarytree_balance(const avl_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binarytree_balance(tree->left) - binarytree_balance(tree->right));
}

/**
 * binarytree_rotate_left - performs a left rotation on binary tree
 * @tree: pointer to root node of tree to rotate
 *
 * Return: pointer to new root node of tree once rotated
 */
avl_t *binarytree_rotate_left(avl_t *tree)
{
	avl_t *newroot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	newroot = tree->right;
	tree->right = newroot->left;
	newroot->left = tree;

	return (newroot);
}

/**
 * binarytree_rotate_right - performs a right rotation on binary tree
 * @tree: pointer to root node of tree to rotate
 *
 * Return: pointer to new root node of tree once rotated
 */
avl_t *binarytree_rotate_right(avl_t *tree)
{
	avl_t *newroot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	newroot = tree->left;
	tree->left = newroot->right;
	newroot->right = tree;

	return (newroot);
}

/**
 * bt_insert - insert value in binary search tree
 * @tree: pointer to root node of binary tree to insert value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to created node or NULL (failure)
 */
avl_t *bt_insert(avl_t *tree, int value)
{
	int bal;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		tree->left = bt_insert(tree->left, value);
	else if (value > tree->n)
		tree->right = bt_insert(tree->right, value);
	else
		return (NULL);

	bal = binarytree_balance(tree);
	if (bal > 1)
	{
		if (value < tree->left->n)
		{
			return (binarytree_rotate_right(tree));
		}
		else
		{
			tree->left = binarytree_rotate_left(tree->left);
			return (binarytree_rotate_right(tree));
		}
	}

	if (bal < -1)
	{
		if (value > tree->right->n)
		{
			return (binarytree_rotate_left(tree));
		}
		else
		{
			tree->right = binarytree_rotate_right(tree->right);
			return (binarytree_rotate_left(tree));
		}
	}

	return (tree);
}

/**
 * avl_insert - inserts value in an avl tree
 * @tree: double pointer to root node of avl tree for inserting the value
 * @value: value to store in node to be inserted
 *
 * Return: pointer to created node or NULL (failure)
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	*tree = bt_insert(*tree, value);

	return (*tree);
}
