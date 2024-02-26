#include "binary_trees.h"

/**
 * binary_tree_inorder - visit the tree in inorder (left, self, right)
 * @tree: pointer to node
 * @func: used to print self
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
