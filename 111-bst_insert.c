#include "binary_trees.h"

/**
 * bst_insert - inserts a value in binary search tree
 * @tree: double pointer to root node of the BST to insert value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to created node or NULL (failure)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *curr, *p;

	if (tree == NULL)
		return (NULL);
	new = malloc(sizeof(bst_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = new->right = new->parent = NULL;
	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}
	curr = *tree;
	p = NULL;
	while (curr != NULL)
	{
		p = curr;
		if (value < curr->n)
		{
			curr = curr->left;
		}
		else if (value > curr->n)
		{
			curr = curr->right;
		}
		else
		{
			free(new);
			return (NULL);
		}
	}
	if (value < p->n)
		p->left = new;
	else
		p->right = new;
	new->parent = p;

	return (new);
}
