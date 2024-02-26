#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if given node is a root or not
 * @node: pointer to node of the tree
 * Return: 1 or 0
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node)
		return (node->parent == NULL);
	return (0);
}
