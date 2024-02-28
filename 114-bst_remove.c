#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_node;

	if (!root)
		return (0);
	if (root->n == value)
	{
		new_node = root->left ? root->left : root->right;
		if (root->left && root->right)
		{
			for (new_node = root->right; new_node->left; new_node = new_node->left)
				;
			new_node->left = root->left;
			root->left->parent = new_node;
			if (new_node->parent != root)
			{
				new_node->parent->left = new_node->right;
				if (new_node->right)
					new_node->right->parent = new_node->parent;
			}
			if (root->right != new_node)
			{
				root->right->parent = new_node;
				new_node->right = root->right;
			}
			new_node->parent = root->parent;
		}
		if (root->parent && root->parent->left == root)
			root->parent->left = new_node;
		else if (root->parent)
			root->parent->right = new_node;
		for (new_node = root->parent ? root->parent : new_node;
		     new_node && new_node->parent; new_node = new_node->parent)
			;
		free(root);
		return (new_node);
	}
	if (root->n > value)
		return (bst_remove(root->left, value));
	return (bst_remove(root->right, value));
}

