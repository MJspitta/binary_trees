#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as left child of another node
 * @parent: pointer to the node to inset the left child in
 * @value: value to store in the new node
 *
 * Return: pointer to created node or NULL (failure)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = parent->left;
	newnode->right = NULL;
	if (parent->left != NULL)
		parent->left->parent = newnode;

	parent->left = newnode;

	return (newnode);
}
