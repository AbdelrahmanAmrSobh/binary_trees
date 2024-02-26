#include "binary_trees.h"

/**
 * binary_tree_nodes - count nodes of tree starting for current node
 * @tree: current node
 * Return: count of nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && tree->right)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	if (tree->left)
		return (1 + binary_tree_nodes(tree->left));
	if (tree->right)
		return (1 + binary_tree_nodes(tree->right));
	return (0);
}
