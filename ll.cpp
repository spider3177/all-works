#include <iostream>
using namespace std;

class Node{
	public:
	//data
	int data;
	//pointer to the next node
	Node * next;
	// constructor that make the pointer to NULL
	Node(){
		next = NULL;
	}
		
};

class ll{
	//Head + Circles inside linked with each other
	public:
	//Head--> node type pointer
	Node * head;
	Node * tail;
	
	//construct
	ll(){	
		head = NULL;
		tail = NULL;
	}
	//Circles inside linked with each other
	//Rules how circles will be linked each other
	
	//Insertion
	void insert(int value){
		//if 1st node is added
		Node * temp = new Node;
		//insert value inside the node
		temp->data = value;
		//1st node only
		if (head == NULL){
			head = temp;
		}
		//any other nodes
		else{			
			tail->next = temp;		
		}	
		tail = temp;
	}
		
	//A->B =C means 
	//a.b = c same as the previous just a here is an object 

	void insertat(int pos, int value){
		Node * temp = new Node;
		temp->data = value;
		Node * current = head;
		if(pos==1)
		{
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				temp->next = head;
				head = temp;
			}
		temp->next=current;
		head = temp;
		}
		//reach the place before the postion
		else if(pos>1){
		Node * current = head;
		int i = 1;
		while (i<pos-1){
		i++;
		current = current->next;
		}
		//create a node
		//Node * temp = new Node;
		//temp->data = value;
		//moving pointers like magic
		temp->next = current->next;
		current->next = temp;
		}
	}


	//Deletion of the last element 
	void delet(){
		
		//store the tail in temp
		Node * temp = tail;
		//before tail has to point to null
		Node * current = head;
		if(current->next == NULL){
			head=NULL;
			delete current;
		}
		else{
			while(current->next != tail){
				current = current->next;
			}
			current->next = NULL;
			
			//update tail
			tail = current;
			//delete temp
			delete temp;
		}
	}	

	void revdisplay(){
	revdisplay2(head);
	cout<<endl;
	}
	void revdisplay2(Node * current){
	//moves to next (till available)
		if(current == NULL) return;
		else{
			revdisplay2(current->next);
			cout<<current->data<<"->";
		}
	//while coming back you print.
	}

	void revLL(){
		Node * temp = head;
		revLL2(head);
		temp-> next = NULL;
	}
	void revLL2(Node * current){
		//condition for empty linkedlist
		if(current == NULL) return;
		//condition for one element
		else if(current->next == NULL){
			head = current;
			return;
		}
		//reverse for the rest
		else{
			//current->next=current;
			revLL2(current->next);
			current->next->next=current;

		}

	}
	void ci(){
		Node * current =head;
		int i = 1;
		while (current->next != NULL){
			current = current->next;
			i++;
		}
		cout<<i<<endl;
		
	}
	//Display 
	 void deleteat(int pos){
        // To Do
		Node * current = head;
		Node * temp;
		if(pos==1){
			head=current->next;
			temp=current;
			delete temp;
		}		
		else if(pos>1){
		int i = 1;
		//getting the desired position
			for(i=1;i<pos-1;i++){
				current = current->next;
			}
		//assigning the desired element to the varible
			if(current -> next != NULL){
				temp = current->next;
		//completing the circle
				current->next = temp->next;
		//deleting the variable
				delete temp;	
			}
		}
    }
	
	void display(){
		Node * current = head;
		while(current!= NULL){
			cout<<current->data << "->";
			current = current->next;
		}
		cout<<endl;
	}
	
};
/*
int main(){
	ll l1;
	int a,b,c;
	cout<<"number of inputs"<<endl;
	cin>>a;
	cout<<"give me the numbers"<<endl;
	for(int i=1;i<a+1;i++){
		cin>>b;
		l1.insert(b);
	}
	l1.display();
	cout<<endl;
	l1.insertat(1,8);
	l1.display();
	cout<<endl;
	l1.delet();
	l1.display();
	cout<<endl;
	l1.insertat(2,8);
	l1.display();
	l1.revdisplay();
	l1.revLL();

	cout<<"\nposition"<<endl;
	cin>>c;
	l1.deleteat(c);
	l1.display();
	cout<<endl;
return 0;
}
*/
