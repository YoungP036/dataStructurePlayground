//include -c flag when compiling for files without a main
#include<iostream>
typedef struct node{
	int data;
	node  *next;
	
}node;
class linkedlist{
	private:
	node *head, *tail;
	public:
	
	//constructor
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	
	//default insert will insert at the start
	//create new node and give it the new value, point it to old head
	//head must always point to 1st node so head=newnode/temp
	void insert(int value){
		if(value!=(int)NULL){
			node *temp = new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
	}
	
	bool search(int value){
		node *temp = new node;
		temp=head;
		//walk the list until hit end or find val
		while(temp->data!=value&&temp!=NULL){
			temp=temp->next;
		}
		if(temp!=NULL) return true;
		else return false;
	}
	
	void remove(int value){
		if(value!=(int)NULL){
			node *temp = new node;
			node *prev = new node;
			temp=head;
			//find node to remove
			while(temp->data!=value && temp!=NULL){
				prev=temp;
				temp=temp->next;
			}
			//if temp=null the value is not in our list, if it is we remove
			if(temp!=NULL){
				//case 1: we are removing the only node in the list, thus prev=null
				if(prev==NULL)
					head=NULL;
				//case 2: prev exists, point it to the node after p
				else
					prev->next=temp->next;
			}
		}
	}
	
	void printall(){
		node* p = new node;
		p=head;
		while(p!=NULL){
			std::cout<<p->data<<"\t";
			p=p->next;
		}
	}	
};

int main(){
	std::cout<<"compiled successfully\n";
}
