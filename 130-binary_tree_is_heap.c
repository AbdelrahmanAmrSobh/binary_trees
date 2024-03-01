#include "binary_trees.h"

/**
 * binary_tree_is_heap - check if given tree is heap
 * @tree: root of tree
 * Return: 1 true or 0 false
*/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && tree->right)
		return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
	if (tree->left || tree->right)
		return (0);
	return (tree->parent ? tree->parent->n > tree->n ? 1 : 0 : 1);
}
