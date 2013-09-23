#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int default_comp_fn(void *l_data, void *r_data)
{
	if (*((int*) l_data) < *((int*) r_data))
		return 1;
	else
		return 0;
} 


bst_t* 
bst_create(char name[30],
		int (*comp_fn)(void *l_data, void *r_data))
{
	bst_t *bst = NULL;
	bst = (bst_t *) malloc(sizeof(bst_t));
	if (!bst){
		fprintf(stderr, "Error in malloc\n");
		return bst; 
	} 
		
	strncpy(bst->name, name, 30);
	if (comp_fn) {
		bst->comp_fn = comp_fn;
	} else 
		bst->comp_fn = &default_comp_fn;	

}

int _bst_node_add (bst_t *tree,
		bst_node_t *cur_node, 
		bst_node_t *new_node)
{
	if (!tree || !cur_node || !new_node) {
		fprintf(stderr, "Unable to add!");
		return INVALID_ARG;
	}
		

	if ((*tree->comp_fn)(cur_node->data,
				 new_node->data)) {
		//LEFT
		if(!cur_node->left) {
			cur_node->left = new_node;
			return 0;
		} else {
			_bst_node_add(tree, cur_node->left, 
					new_node);
		}
	} else {
		//RIGHT
		if(!cur_node->right) {
			cur_node->right = new_node;
			return 0;
		} else {
			_bst_node_add(tree, cur_node->right, 
					new_node);	
		}
	} 

	return SUCCESS;
}
		

int bst_add(bst_t *tree, bst_node_t *node)
{
	int ret_val = SUCCESS;

	if (!tree || !node) {
		fprintf(stderr, "Invalid argument");
	}

	if (!tree->root) {
		tree->root = node;
		return ret_val;	
	} 

	if ((*tree->comp_fn)(tree->root->data, node->data)) {
		if (!tree->root->left){
			tree->root->left = node;
			return 0;
		} else  {
			_bst_node_add(tree, tree->root->left, node);
		}
	} else {
		if (!tree->root->right) {
			tree->root->right = node;
			return 0;
		}
		_bst_node_add(tree, tree->root->right, node);
	}	
	
	return ret_val;
}

int bst_del(bst_t *tree, bst_node_t *node)
{

	return 0;
}

void 
_bst_preorder_node(bst_node_t *node)
{

	if (node)
		printf(" %d \n", *(int *) node->data);
	if (node->left)
		_bst_preorder_node(node->left);
	if (node->right)
		_bst_preorder_node(node->right);
}

void 
bst_preorder(bst_t *tree) 
{
	if (!tree) {
		fprintf(stderr, "Invalid argument to %s",
			__FUNCTION__);
	}
		
	if (tree->root) {
		_bst_preorder_node(tree->root);
	}
}
