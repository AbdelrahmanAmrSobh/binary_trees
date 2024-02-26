#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if tree is full
 * @tree: current root
 * Return: return 1 if full 0 otherwise
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left & right);
	}
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}
