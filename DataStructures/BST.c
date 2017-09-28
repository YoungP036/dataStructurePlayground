#include<stdlib.h>

typedef int (*comparer)(int,int);
typedef struct node{
	int value;
	node* left;
	node* right;
}node;

extern node head;

int add(int value);
int remove(int value);
int search(int value);
void print_all();
int isLeaf(node p);
int insert(node *root, comparer compare, int data){
	
	if(info==NULL) return -1;
	
	if(head==NULL)
		root=new_node(info);
	else{
		int is_left=0;
		int r=0;
		node* p = root;
		node* prev = NULL;
	
		while(p!=NULL){
			r=compare(data,p->data);
			prev=p;
			if(r<0){
				is_left=1;
				p=p->left;
			}
			else{
				is_left=0;
				p=p->right;
			}
		}//end while
		if(is_left)
			prev->left=new_node(data);
		else
			prev->right=new_node(data);
	}//end else	
}

int delete(node *root, int value, comparer compare){
	
}
node* new_node(int data){
	node *new_node=(node*)malloc(sizeof(node));
	if(new_node==NULL){
		printf("out of memory\n");
		exit(-1);
	}
	
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

int isLeaf(node p){
	if(node.left==NULL && node.right==NULL)
		return 1;
	else
		return 0;
}
