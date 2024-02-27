#include "binary_trees.h"

/**
 * binary_tree_levelorder - use function on tree's node going by levels
 * @tree: root
 * @func: function
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const int SIZE = 256;
	binary_tree_t *array[SIZE];
	int head = 1;
	int tail = 0;
	int size = 1;

	if (!tree && !func)
		return;
	array[0] = (binary_tree_t *) tree;
	while (size)
	{
		if (array[tail])
		{
			func(array[tail]->n);
			array[head] = array[tail]->left;
			head = (head + 1) % SIZE;
			array[head] = array[tail]->right;
			head = (head + 1) % SIZE;
			size++;
		}
		tail = (tail + 1) % SIZE;
		while (size && !array[tail])
		{
			tail = (tail + 1) % SIZE;
			size--;
		}
	}
}
