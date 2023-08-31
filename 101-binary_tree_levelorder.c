#include "binary_trees.h"

/**
 * createnode - creates a new node
 * @node: binary tree node for new node to contain
 *
 * Return: pointer to new node or NULL
 */
node_queue_t *createnode(binary_tree_t *node)
{
	node_queue_t *newnode;

	newnode = malloc(sizeof(node_queue_t));
	if (newnode == NULL)
		return (NULL);

	newnode->node = node;
	newnode->next = NULL;

	return (newnode);
}

/**
 * freequeue - frees a queue
 * @head: pointer to head of queue
 *
 * Return: nothing
 */
void freequeue(node_queue_t *head)
{
	node_queue_t *hold;

	while (head != NULL)
	{
		hold = head->next;
		free(head);
		head = hold;
	}
}

/**
 * enqueue - runs a func on a given node and push its children into queue
 * @node: node to print and push
 * @head: pointer to head of queue
 * @tail: pointer to tail of queue
 * @func: pointer to function to call on node
 *
 * Return: nothing
 */
void enqueue(const binary_tree_t *node, node_queue_t *head,
		node_queue_t **tail, void (*func)(int))
{
	node_queue_t *newnode;

	func(node->n);
	if (node->left != NULL)
	{
		newnode = createnode(node->left);
		if (newnode == NULL)
		{
			freequeue(head);
			exit(1);
		}
		(*tail)->next = newnode;
		*tail = newnode;
	}

	if (node->right != NULL)
	{
		newnode = createnode(node->right);
		if (newnode == NULL)
		{
			freequeue(head);
			exit(1);
		}
		(*tail)->next = newnode;
		*tail = newnode;
	}
}

/**
 * dequeue - pops the dead of a queue
 * @head: pointer to head of queue
 *
 * Return: nothing
 */
void dequeue(node_queue_t **head)
{
	node_queue_t *hold;

	hold = (*head)->next;
	free(*head);
	*head = hold;
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	node_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = createnode((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		enqueue(head->node, head, &tail, func);
		dequeue(&head);
	}
}
