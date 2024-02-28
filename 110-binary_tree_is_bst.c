#include "binary_trees.h"

/**
 * max - check if supposed max is actually max
 * @tree: given tree
 * @supposed_max: supposed max in tree
 * Return: 1 or 0 true or false
*/

int max(const binary_tree_t *tree, int supposed_max)
{
	if (!tree)
		return (1);
	if (tree->n >= supposed_max)
		return (0);
	return (max(tree->left, supposed_max) & max(tree->right, supposed_max));
}

/**
 * min - check if supposed min is actually min
 * @tree: given tree
 * @supposed_min: supposed min in tree
 * Return: 1 or 0 true or false
*/

int min(const binary_tree_t *tree, int supposed_min)
{
        if (!tree)
                return (1);
        if (tree->n <= supposed_min)
                return (0);
        return (min(tree->left, supposed_min) & min(tree->right, supposed_min));
}

/**
 * binary_tree_is_bst - check if tree given can be binary search tree
 * @tree: given tree
 * Return: true or false
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!max(tree->left, tree->n))
		return (0);
	if (!min(tree->right, tree->n))
                return (0);
	if (tree->left && tree->right)
		return (binary_tree_is_bst(tree->left) & binary_tree_is_bst(tree->right));
	if (tree->left)
		return (binary_tree_is_bst(tree->left));
	if (tree->right)
		return (binary_tree_is_bst(tree->right));
	return (1);
}
