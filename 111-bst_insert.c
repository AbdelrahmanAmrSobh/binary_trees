#include "binary_trees.h"

/**
 * bst_insert - inserts node in bst
 * @tree: pointer to pointer of root
 * @value: value goes to created node
 * Return: address or null if failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree && !*tree)
		return (tree[0] = binary_tree_node(NULL, value));
	if (tree[0]->n == value)
		return (NULL);
	if (tree[0]->n > value)
	{
		if (tree[0]->left)
			return (bst_insert(&tree[0]->left, value));
		return (tree[0]->left = binary_tree_node(tree[0], value));
	}
	if (tree[0]->right)
		return (bst_insert(&tree[0]->right, value));
	return (tree[0]->right = binary_tree_node(tree[0], value));
}
