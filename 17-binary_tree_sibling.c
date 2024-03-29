#include "binary_trees.h"

/**
 * binary_tree_sibling - return sibling of current node
 * @node: current node
 * Return: address of sibling of current node
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		return (node->parent->left);
	}
	return (NULL);
}
