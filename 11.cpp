#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class node{
    public:
    // Data 
    int data;
    // Pointer to the next node
    node * next;
    // Construct that makes the ptr to NULL
    node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
    void insert(int value){
        
        // Create a new node
        node * temp = new node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
    void display(){
        node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
    void insertat(int value, int pos){
        // To Do
		//declaring the node
		//if position is graeater than one
		node * current = head;
		node * temp = new node(value);
		//if position is greater than 1
		if(pos==1){
			while(current->next!= head){
			current = current->next;
			}
			node * x = current;
			temp->data = value;
			temp->next = head;
			head = temp;
			x->next=head;
		}		
		else if(pos>1){
		int i = 1;
		//getting the position
			while(i<pos-1){
				current=current->next;
				i++;
			}
		//inserting the values
		temp->data=value;
		temp->next=current->next;
		current->next=temp;
		}
    }
    void deleteat(int pos){
        // To Do
		node * current = head;
		node * temp;
		int i = 1;
		if(pos==1){
			head = current->next;
			temp = current;
			delete temp;
			//node * x = head;
			while(current->next->next != head){
				current = current->next;
			}
			current->next = head;
		}	
		else if(pos>1){
		//getting the desired position
			while(i<pos-1){
			current = current->next;
			i++;
			}
		//assigning the desired element to the varible
			temp = current->next;
		//completing the circle
			current->next = temp->next;
		//deleting the variable
			delete temp;
		}
		
    }
    void del(){
        // Deletes the last element.
		node * current = head;
		node * temp;
		while(current->next->next!= head){
			current = current->next;
		}
		//assigning the last element to a variable
		temp = current->next;
		//assigning the previous element as the last element
		current->next = head;
		//deleting the variable
		delete temp;
    }
    void ci(){
        node * current = head;
		int i=1;
		while(current->next != head){
		i++;
		current = current->next;
		}
		cout<<i;
    }

};

int main(){
CSLL cll1;
	int a,b,c,d,e;
	cout<<"the number of inputs"<<endl;
	cin>>a;
	cout<<"give the numbers"<<endl;
    for(int i= 0; i < a; i++){
		cin>>b;
        cll1.insert(b);
    }
	cout<<"the items are:-"<<endl;
	cll1.display();
	cout<<"the number of items are:-"<<endl;
	cll1.ci();
	cout<<endl;
	cll1.del();
	cout<<"after deletion"<<endl;
	cll1.display();
	cout<<endl;
	cout<<"give me the specific position you want to delete"<<endl;
	cin>>c;
	cout<<"after deletion at a specific position"<<endl;
	cll1.deleteat(c);
	cll1.display();
	cout<<endl;
	cout<<"give me the specific position you want to insert"<<endl;
	cin>>e;
	cout<<"give me the number to insert"<<endl;
	cin>>d;
	cout<<"after insertion at a specific position"<<endl;
	cll1.insertat(d,e);
	cll1.display();
	cout<<endl;
}
