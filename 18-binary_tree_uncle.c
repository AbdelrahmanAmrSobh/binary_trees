#include "binary_trees.h"

/**
 * binary_tree_uncle - return uncle of current node
 * @node: current node
 * Return: address of uncle of current node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		return (node->parent->parent->left);
	}
	return (NULL);
}
