#include "binary_trees.h"

/**
 * bst_search - search tree for node
 * @tree: given tree
 * @value: node's value
 * Return: node if found else NULL
*/

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
