#include "binary_trees.h"

/**
 * binary_tree_preorder - visit the tree in preorder (self, left, right)
 * @tree: pointer to node
 * @func: used to print self
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
