#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *m, *d;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	m = first->parent;
	d = second->parent;
	if ((first == d) || !m || (!m->parent && d))
		return (binary_trees_ancestor(first, d));
	else if (m == second || !d || (!d->parent && m))
		return (binary_trees_ancestor(m, second));

	return (binary_trees_ancestor(m, d));
}
