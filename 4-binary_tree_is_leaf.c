#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if given node is a leaf or not
 * @node: pointer to node of the tree
 * Return: 1 or 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node)
		return (node->left == NULL && node->right == NULL);
	return (0);
}
