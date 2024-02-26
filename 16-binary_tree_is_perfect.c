#include "binary_trees.h"

/**
 * get_depth - calculate depth of leftmost node of tree
 * @tree: current node
 * Return: depth
*/

int get_depth(const binary_tree_t *tree)
{
	if (tree)
		return (1 + get_depth(tree->left));
	return (0);
}

/**
 * perfect_tree_check - checks tree if full and left height is same as right's
 * @tree: current node
 * @depth: current depth
 * Return: 1 if true is balanced 0 otherwise
*/

int perfect_tree_check(const binary_tree_t *tree, int depth)
{
	if (!tree || depth < 0)
		return (!depth);
	return (perfect_tree_check(tree->left, depth - 1) &
		perfect_tree_check(tree->right, depth - 1));
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: given root
 * Return: 1 tree is perfect 0 tree is not
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (perfect_tree_check(tree, get_depth(tree)));
}
