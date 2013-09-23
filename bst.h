#ifndef __BST_H
#define __BST_H


enum {
	SUCCESS= 0,
	NO_MEM,
	INVALID_ARG
} bst_ret_val;

typedef struct bst_node_ {
	void *data;
	struct bst_node_ *left;
	struct bst_node_ *right;
	//int height;

} bst_node_t ;

typedef struct bst_ {
	bst_node_t *root;
	char name[20];
	int (*comp_fn)(void* r_data, void* l_data);	
} bst_t;



bst_t* bst_create(char name[30],
		int (*comp_fn)(void *r_data, void *l_data));
		

int bst_add(bst_t *tree, bst_node_t *node);

int bst_del(bst_t *tree, bst_node_t *node);

void bst_preorder(bst_t *tree);

#endif /* __BST_H */
