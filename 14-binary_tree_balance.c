#include "binary_trees.h"

/**
 * get_depth - calculate depth of left and right
 * @tree: current node
 * Return: max depth of current node
*/

int get_depth(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	left = tree->left ? 1 + get_depth(tree->left) : 1;
	right = tree->right ? 1 + get_depth(tree->right) : 1;
	return (left > right ? left : right);
}

/**
 * binary_tree_balance - checks the balance of left and right of current node
 * @tree: current node
 * Return: depth of left - depth of right
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	left = get_depth(tree->left);
	right = get_depth(tree->right);
	return (left - right);
}
