#include "binary_trees.h"

/**
 * bt_insert - insert value in binary tree
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

	bal = binary_tree_balance(tree);
	if (bal > 1)
	{
		if (value < tree->left->n)
		{
			return (binary_tree_rotate_right(tree));
		}
		else
		{
			tree->left = binary_tree_rotate_left(tree->left);
			return (binary_tree_rotate_right(tree));
		}
	}

	if (bal < -1)
	{
		if (value > tree->right->n)
		{
			return (binary_tree_rotate_left(tree));
		}
		else
		{
			tree->right = binary_tree_rotate_right(tree->right);
			return (binary_tree_rotate_left(tree));
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
