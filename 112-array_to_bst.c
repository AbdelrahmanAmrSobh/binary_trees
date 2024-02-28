#include "binary_trees.h"

/**
 * array_to_bst - turn an array to bst
 * @array: array to turn
 * @size: size of array
 * Return: root of tree
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index = 0;

	while (index < size)
		bst_insert(&tree, array[index++]);
	return (tree);
}
