#include "binary_trees.h"

/**
 * binary_tree_insert_left - creates node and assign it with value
 *			     add node to the left of parent
 *			     if another node exist as left of parent
 *			     existing node becomes the left child of created node
 * @parent: pointer to parent of supposed node
 * @value: value goes into the node
 * Return: address of created node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent)
		node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->right = NULL;
	node->left = parent->left;
	parent->left = node;
	if (node->left)
	{
		node->left->parent = node;
		node->left->left = NULL;
	}
	return (node);
}
