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

/**
 * binary_tree_is_avl - check if given tree is avl tree
 * @tree: given tree
 * Return: true or false 1 for true 0 for false
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance = binary_tree_balance(tree);

	if (balance > 1)
		return (0);
	if (balance < -1)
		return (0);
	if (!tree)
		return (0);
	if (!max(tree->left, tree->n))
		return (0);
	if (!min(tree->right, tree->n))
		return (0);
	if (tree->left && tree->right)
		return (binary_tree_is_avl(tree->left) & binary_tree_is_avl(tree->right));
	if (tree->left)
		return (binary_tree_is_avl(tree->left));
	if (tree->right)
		return (binary_tree_is_avl(tree->right));
	return (1);
}
