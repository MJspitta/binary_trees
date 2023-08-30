#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as right child of another node
 * @parent: pointer to node to insert right child in
 * @value: value to store in new node
 *
 * Return: pointer to created node or NULL (failure)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = parent->right;
	if (parent->right != NULL)
		parent->right->parent = newnode;

	parent->right = newnode;

	return (newnode);
}
