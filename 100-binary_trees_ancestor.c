#include "binary_trees.h"

/**
 * find_node - search for target in given tree
 * @tree: given tree
 * @target: node to find
 * Return: if found 1 else 0
*/

int find_node(const binary_tree_t *tree, const binary_tree_t *target)
{
	int found = 0;

	if (!tree)
		return (0);
	if (tree == target)
		return (1);
	found = find_node(tree->left, target);
	if (found)
		return (1);
	return (find_node(tree->right, target));
}

/**
 * binary_trees_ancestor - find common ancestor between first and second
 * @first: first node
 * @second: second node
 * Return: address of common ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *common_ancestor = (binary_tree_t *) second;
	binary_tree_t *prev = (binary_tree_t *) first;
	int result;

	if (!first || !second)
		return (NULL);
	result = find_node(first, second);
	if (result)
		return (prev);
	result = find_node(second, first);
	if (result)
		return (common_ancestor);
	for (common_ancestor = first->parent; common_ancestor;
	     common_ancestor = common_ancestor->parent)
	{
		if (common_ancestor->left == prev)
			result = find_node(common_ancestor->right, second);
		else
			result = find_node(common_ancestor->left, second);
		if (result)
			break;
		prev = prev->parent;
	}
	return (common_ancestor);
}
