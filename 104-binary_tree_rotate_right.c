#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates tree to the right
 * @tree: given tree
 * Return: new root
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree ? tree->left : NULL;

	if (!tree || !new_root)
		return (tree ? tree : NULL);
	tree->left = new_root->right;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->right = tree;
	if (tree->left)
		tree->left->parent = tree;
	return (new_root);
}
