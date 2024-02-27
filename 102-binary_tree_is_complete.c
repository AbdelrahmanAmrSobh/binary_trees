#include "binary_trees.h"

/**
 * count_nodes - it counts the nodes in tree
 * @tree: given tree
 * Return: number of nodes
*/

int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * isComplete - helper function for binary_tree_is_complete
 *		that checks for complete binary tree
 * @tree: given tree
 * @index: index of parent node
 * @nodesCount: number of nodes in the tree, this number is fixed
 * Return: if complete 1 else 0
*/

int isComplete(const binary_tree_t *tree, int index, int nodesCount)
{
	if (!tree)
		return (1);
	if (index >= nodesCount)
		return (0);
	return (isComplete(tree->left, 2 * index + 1, nodesCount) &&
		isComplete(tree->right, 2 * index + 2, nodesCount));
}

/**
 * binary_tree_is_complete - check if binary tree is complete
 *			     I wrote the code myself but logic/algorithm source
 *			     is geeksforgeeks link is too long to write it here
 * @tree: root of tree
 * Return: complete = 1 else 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (isComplete(tree, 0, count_nodes(tree)));
}
