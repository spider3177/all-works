#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    node * next;
    node * prev;
    // Construct that makes the ptr to NULL
    node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    node * head;
    DLL(){
        head = NULL;
    }
    void insert(int value){
        // Create a new node
        node * temp = new node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
    void display(){
        node *current = head;
        node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
    void InsertAt(int value, int pos){
        // To Do
    }
    void deleteat(int a){
        node * current = head;
		node * temp;
		int i=0;
		while(i<a-1){
			current= current->next;
			i++;
		}
		current->prev->next=current->next;
		current->next->prev=current->prev;
		delete current;
		
    }
    void del(){
        // Deletes the last element.
		node * current = head;
		//specifying the end position
		while(current->next !=NULL)
			{current=current->next;}
		//deleting the end position
				current->prev->next= NULL;
				delete current;
    }
    void ci(){
        // Counts the Number of items.
		node * current = head;
		int i=1;
		while(current->next != NULL){
			i++;
			current = current->next;
		}
		cout<<i<<endl;
    }

};

int main(){
    DLL dll1;
	int a,b,c,d,e;
	cout<<"the number of inputs"<<endl;
	cin>>a;
	cout<<"give the numbers"<<endl;
    for(int i= 0; i < a; i++){
	cin>>b;
        dll1.insert(b);
    }
	cout<<"the items are:-"<<endl;
	dll1.display();
	cout<<"the number of items are:-"<<endl;
	dll1.ci();
	dll1.del();
	cout<<"after deletion"<<endl;
	dll1.display();
	cout<<endl;
	cout<<"give me the specific position you want to delete"<<endl;
	cin>>c;
	cout<<"after deletion at a specific position"<<endl;
	dll1.deleteat(c);
	dll1.display();
	cout<<endl;
}
