#include "binary_trees.h"

/**
 * binary_tree_node - creates node and assign value to it
 *		      connect the node with parent
 * @parent: pointer to supposed parent of node
 * @value: value goes to node
 *
 * Return: address of new assigned node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}
