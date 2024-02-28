#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates tree to the left
 * @tree: given tree
 * Return: new root
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree ? tree->right : NULL;

	if (!tree || !new_root)
		return (tree ? tree : NULL);
	tree->right = new_root->left;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->left = tree;
	if (tree->right)
		tree->right->parent = tree;
	return (new_root);
}
