#include<stdlib.h>
typedef int (*comparer)(int,int);
typedef struct node{
	int info;
	struct node *left;
	struct node *right;
} node;

// struct node{
// 	int info;
// 	struct node* left;
// 	struct node* right;
// }
// typedef struct node node;
node* head;
extern nodeCount=0;
node* new_node(int value);
int add(int value);
int remove(int value);
int insert(node* root, int value);
int search(int value);
void print_all();
int isLeaf(node* p);

int main(){
	head=new_node(17);
	print_count();
	print_all(head);
	insert(head,5);
	print_count();
	print_all(head);
	insert(head,3);
	insert(head,7);
	insert(head,11);
	insert(head,13);
	print_count();
	print_all(head);
	return 0;
}
void print_count(){
	printf("***Printing %d nodes***\n",nodeCount);
}
void print_all(node *p){
	if(p==NULL) return;
	else{
		if(p->left!=NULL)
			print_all(p->left);
		printf("%d\n",p->info);
		if(p->right!=NULL)
			print_all(p->right);		
	}
	return;
}
int insert(node *root,int value){
	
	if(value==NULL) return -1;
	
	if(root==NULL)
		root=new_node(value);
	else{
		int is_left=0;
		node* p = root;
		node* prev = NULL;
	
		//walk the tree until p is null, at that point use prev's ref to it and proceed
		while(p!=NULL){
			prev=p;
			if(value < p->info){
				is_left=1;
				p=p->left;
			}
			else{
				is_left=0;
				p=p->right;
			}
		}//end while
		//at this point we are 'in' an empty node pointed to by prev, init new node with value
		if(is_left)
			prev->left=new_node(value);
		else
			prev->right=new_node(value);
	}//end else	
}

int remove(node *root, int value){
	//CASE 1: single node tree
	if(isLeaf(root))
		if(root->info==value)
			root=NULL;
	//CASE 2: mature tree
	else{
		int is_left=0;
		node* p = root;
		node* prev = NULL;

		//walk the tree
		while(p!=NULL && p->info != value){
			prev=p;
			if(value < p->info){
				is_left=1;
				p=p->left;
			}
			else{
				is_left=0;
				p=p->right;
			}

		//value exists in tree
		if(p->info == value){
			//CASE 2.1: value's node is a leaf
			if(isLeaf(p)){
				p=NULL
			}
			//CASE 2.2: right child exists
			else if(p->left==NULL && p->right!=NULL){
				if(is_left)
					prev->left=p->right;
				else
					prev->right=p->right;
			}
			//CASE 2.3: left child exists			
			else if(p->left!=NULL && p->right==NULL){
				if(is_left)
					prev->left=p->left;
				else
					prev->right=p->left;
			}
			//CASE 2.4: both children exist			
			else if(p->left!=NULL && p->right!=NULL){
			//TODO smallest node in right subtree, or largest node in left subtree? i forget, draw it but sleep first !!
			}
		}
		}//end while

	}
}
node* new_node(int value){
	node *new_node=(node*)malloc(sizeof(node));
	if(new_node==NULL){
		printf("out of memory\n");
		exit(-1);
	}
	
	new_node->info=value;
	new_node->left=NULL;
	new_node->right=NULL;
	nodeCount++;
	return new_node;
}

int isLeaf(node* p){
	if(p->left==NULL && p->right==NULL)
		return 1;
	else
		return 0;
}
