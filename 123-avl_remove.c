#include "binary_trees.h"

/**
 * binary_tree_remove - remove node from tree
 * @root: pointer to root node of tree for removing node
 * @value: value to remove in tree
 *
 * Return: pointer to new root node of tree after removing value
 */
avl_t *binary_tree_remove(avl_t *root, int value)
{
	avl_t *hold, *s;
	int bal;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = binary_tree_remove(root->left, value);
	else if (value > root->n)
		root->right = binary_tree_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			hold = root->right;
			free(root);
			return (hold);
		}
		else if (root->right == NULL)
		{
			hold = root->left;
			free(root);
			return (hold);
		}
		else
		{
			s = root->right;
			while (s->left != NULL)
				s = s->left;
			root->n = s->n;
			root->right = binary_tree_remove(root->right, s->n);
		}
	}
	bal = binary_tree_balance(root);
	if (bal > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (bal > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (bal < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (bal < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - removes a node from an avl tree
 * @root: pointer to the root node of tree for removing a node
 * @value: value to remove in tree
 *
 * Return: opinter to new root node of tree after removing value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	return (binary_tree_remove(root, value));
}
