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
 * reBalancing - rebalance tree
 * @tree: given tree
 * @new_node: node added to tree
 * @value: value of new node
*/

void reBalancing(avl_t **tree, avl_t *new_node, int value)
{
	avl_t *going_up = new_node ? new_node->parent : NULL;
	avl_t *save_point = going_up;
	int balance = binary_tree_balance(going_up);

	while (going_up)
	{
		save_point = going_up->parent;
		if (balance > 1)
		{
			if (going_up->left->n > value)
				going_up = binary_tree_rotate_right(going_up);
			else
			{
				going_up->left = binary_tree_rotate_left(going_up->left);
				going_up = binary_tree_rotate_right(going_up);
			}
		}
		else if (balance < -1)
		{
			if (going_up->right->n < value)
				going_up = binary_tree_rotate_left(going_up);
			else
			{
				going_up->right = binary_tree_rotate_right(going_up->right);
				going_up = binary_tree_rotate_left(going_up);
			}
		}
		while (going_up->parent)
			going_up = going_up->parent;
		*tree = going_up;
		going_up = save_point;
		balance = binary_tree_balance(going_up);
	}
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

	reBalancing(tree, new_node, value);
	return (new_node);
}
