#include "binary_trees.h"

/**
 * binary_tree_depth - calculate depth of current node
 * @tree: pointer to current node
 * Return: depth of current node
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
