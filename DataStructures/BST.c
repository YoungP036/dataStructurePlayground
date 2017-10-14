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
		int r=0;
		node* p = root;
		node* prev = NULL;
	
		while(p!=NULL){
			// r=compare(value,p->info);
			prev=p;
			if(value<p->info){
			// if(r<0){
				is_left=1;
				p=p->left;
			}
			else{
				is_left=0;
				p=p->right;
			}
		}//end while
		if(is_left)
			prev->left=new_node(value);
		else
			prev->right=new_node(value);
	}//end else	
}

int delete(node *root, int value, comparer compare){
	
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
