#include "binary_trees.h"

/**
 * array_to_avl - turn an array to bst
 * @array: array to turn
 * @size: size of array
 * Return: root of tree
*/

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index = 0;

	while (index < size)
		avl_insert(&tree, array[index++]);
	return (tree);
}
