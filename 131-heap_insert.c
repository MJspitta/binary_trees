#include "binary_trees.h"

/**
 * heapup - inserts a value in max binary heap
 * @node: node
 *
 * Return: node
 */
heap_t *heapup(heap_t *node)
{
	int hold;

	if (node->parent != NULL && node->parent->n < node->n)
	{
		hold = node->n;
		node->n = node->parent->n;
		node->parent->n = hold;

		return (heapup(node->parent));
	}

	return (node);
}

/**
 * heap_insert - inserts a value in max binary heap
 * @root: double pointer to root node of heap to insert value
 * @value: value to store in node to be inserted
 *
 * Return: pointer to created node or NULL (failure)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *curr;

	if (root == NULL)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);
	if (*root == NULL)
		*root = new;
	else
	{
		curr = *root;
		while (curr->left != NULL || curr->right != NULL)
		{
			if (curr->left != NULL && curr->right != NULL)
			{
				if (curr->left->n > curr->right->n)
					curr = curr->left;
				else
					curr = curr->right;
			}
			else if (curr->left != NULL)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr->left == NULL)
			curr->left = new;
		else
			curr->right = new;
		new->parent = curr;
		heapup(new);
	}

	return (new);
}
