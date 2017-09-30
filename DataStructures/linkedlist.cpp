

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
<<<<<<< HEAD
		node *temp = new node;
		temp=head;
		//walk the list until hit end or find val
		while(temp->data!=value&&temp!=NULL){
			std::cout<<"looping in search\n";
			temp=temp->next;
		}
		if(temp!=NULL) return true;
		else return false;
	}
	
	void remove(int value){
		if(value!=(int)NULL){
			node *temp = new node;
			node *prev = NULL;
			temp=head;
			//find node to remove
			while(temp->data!=value && temp->next!=NULL){
				std::cout<<"while iterating\n";
				prev=temp;
				temp=temp->next;
			}
			//if temp=null the value is not in our list, if it is we remove
			if(temp!=NULL){
				//case 1: we are removing the only node in the list, thus prev=null
				if(prev==NULL){
					std::cout<<"Removing head node\n";
					head=NULL;}
				//case 2: prev exists, point it to the node after p
				else{
					std::cout<<"Removing deeper node\n";
					prev->next=temp->next;}
=======
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
>>>>>>> 131f879e308306e423ead30f73cfe082be45ab58
			}
			std::cout<<"exiting remove\n";
		}
	}
	
	void printall(){
		node* p = new node;
		p=head;
		std::cout<<"\n\nprinting list\n";
		while(p!=NULL){
			std::cout<<p->data<<"\n";
			p=p->next;
		}
	}	
};

int main(){
	std::cout<<"compiled successfully\n";
	linkedlist* list = new linkedlist();
	list->insert(10);
	list->insert(15);
	if(list->search(15)==true) std::cout<<"15 search true, good\n";
	if(list->search(20)==false) std::cout<<"20 search false, good\n";
	else std::cout<<"20 search ret true, BAD\n";
	list->remove(10);
	list->remove(15);
	list->printall();
	if(list->search(15)==false) std::cout<<"15 search ret false, good\n";
	else std::cout<<"15 search ret true, bad!\n";

}
