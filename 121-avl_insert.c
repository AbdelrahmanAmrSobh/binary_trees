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

/**
 * avl_insert - insert into avl tree and rebalance if needed
 * @tree: given tree
 * @value: value goes into created node to insert into tree
 * Return: new node
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = bst_insert(tree, value);
	avl_t *going_up = new_node->parent;
	int balance = binary_tree_balance(going_up);

	while (going_up)
	{
		if (1 >= balance && balance >= -1)
			going_up = going_up->parent;
		else if (balance == 2)
		{
			if (going_up->left->n > value)
				binary_tree_rotate_right(going_up);
			else
			{
				binary_tree_rotate_left(going_up->left);
				binary_tree_rotate_right(going_up);
			}
		}
		else
		{
			if (going_up->right->n > value)
				binary_tree_rotate_left(going_up->right);
			else
			{
				binary_tree_rotate_right(going_up->right);
				binary_tree_rotate_left(going_up);
			}
		}
		balance = binary_tree_balance(going_up);
	}
	return (new_node);
}
