

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
			if(head!=NULL){
				node *temp = new node;
				temp=head;
				//walk the list until hit end or find val
				while(temp->data!=value&&temp->next!=NULL){
					temp=temp->next;
				}
				if(temp->data==value) return true;
				else return false;
				}
			return false;
	}
	
	void remove(int value){
		if(head!=NULL){
			if(value!=(int)NULL){
				node *temp = new node;
				node *prev=NULL;
				temp=head;
				//find node to remove
				while(temp->data!=value && temp->next!=NULL){
					prev=temp;
					temp=temp->next;
				}
				//if temp=null the value is not in our list, if it is we remove
				if(temp!=NULL){
					//case 1: we are removing the only node in the list, thus prev=null
					if(prev==NULL){
						std::cout<<"removing head\n";
						head=NULL;
					}
					//case 2: prev exists, point it to the node after p
					else{
						std::cout<<"removing not head node\n";
						prev->next=temp->next;
					}
				}
			}
			std::cout<<"exiting remove\n";
		}
	}
	
	void printall(){
		node* p = new node;
		p=head;
		if(p==NULL) std::cout<<"**List is empty**\n";
		else{
			std::cout<<"**printing list**\n";
			while(p!=NULL){
				std::cout<<p->data<<"\n";
				p=p->next;
			}//end while
		}//end else
	}//end print	
};//end class

int main(){
	std::cout<<"compiled successfully\n";
	linkedlist* list = new linkedlist();
	list->insert(10);
	list->insert(15);
	if(list->search(15)==true) std::cout<<"15 search true, **GOOD\n";
	else std::cout<<"15 search ret false, **BAD!\n";
	if(list->search(20)==false) std::cout<<"20 search false, **GOOD\n";
	else std::cout<<"20 search ret true, **BAD!\n";
	std::cout<<"calling print on list {10,15}\n";
	list->printall();
	std::cout<<"calling remove(10)\n";
	list->remove(10);
	std::cout<<"calling remove(15)\n";
	list->remove(15);
	std::cout<<"calling printall on empty list\n";
	list->printall();
	if(list->search(15)==false) std::cout<<"15 search ret false, **GOOD\n";
	else std::cout<<"15 search ret true, **BAD!\n";

}
