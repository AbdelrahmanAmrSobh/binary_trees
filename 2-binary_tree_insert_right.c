#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates node and assign it with value
 *			      add node to the right of parent
 *			      if another node exist as right of parent
 *			      existing node becomes the right child of created node
 * @parent: pointer to parent of supposed node
 * @value: value goes into the node
 * Return: address of created node
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent)
		node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = parent->right;
	parent->right = node;
	if (node->left)
	{
		node->right->parent = node;
		node->right->right = NULL;
	}
	return (node);
}
