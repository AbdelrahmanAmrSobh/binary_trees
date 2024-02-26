#include "binary_trees.h"

/**
 * binary_tree_leaves - count leaves of current node
 * @tree: current node
 * Return: number of leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && tree->right)
		return (2);
	return (1);
}
