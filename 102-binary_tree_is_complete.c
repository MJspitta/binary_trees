#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 (complete) or 0 (NULL)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int leaf, front, rear;
	const binary_tree_t **queue, *curr;

	if (tree == NULL)
		return (0);

	leaf = 0;
	front = 0;
	rear = 0;
	queue = malloc(sizeof(const binary_tree_t *) * 10000);
	if (queue == NULL)
		exit(EXIT_FAILURE);

	queue[rear++] = tree;
	while (front  < rear)
	{
		curr = queue[front++];
		if (curr == NULL)
		{
			leaf = 1;
		}
		else
		{
			if (leaf)
			{
				free(queue);
				return (0);
			}

			queue[rear++] = curr->left;
			queue[rear++] = curr->right;
		}
	}

	free(queue);

	return (1);
}
