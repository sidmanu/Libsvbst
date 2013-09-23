#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bst.h"

int main()
{

	bst_t *my_tree;
	int i = 0;
	int data_int[]= 
	{
	5,
	4,
	6,
	2,
	1
	};

	my_tree = bst_create("My_BST", NULL);
	
	if (!my_tree) 
		printf("Unable to create tree!!!!\n");	
	bst_node_t *node = NULL;

	for (i = 0; i < 5; i++) {
		node = (bst_node_t *) malloc(sizeof(bst_node_t));
		memset(node, 0, sizeof(bst_node_t));
		node->data = (void *) &data_int[i];
		bst_add(my_tree, node);
	}

	bst_preorder(my_tree);	
	return 0;
}


