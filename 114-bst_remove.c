#include "binary_trees.h"

/**
 * find_min_bst - minimum value of binary search tree
 * @rootnode: pointer to root node of bst to search
 *
 * Return: minimub value in tree
 */
bst_t *find_min_bst(bst_t *rootnode)
{
	bst_t *curr;

	curr = rootnode;
	while (curr && curr->left != NULL)
		curr = curr->left;

	return (curr);
}

/**
 * bst_remove - removes a node from a binary search tree
 * @root: pointer to root node of tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to new root node of tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *hold, *min_subtree;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
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
		min_subtree = find_min_bst(root->right);
		root->n = min_subtree->n;
		root->right = bst_remove(root->right, min_subtree->n);
	}

	return (root);
}
