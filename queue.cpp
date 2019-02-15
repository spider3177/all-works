#include <iostream>
#include "ll.cpp"
using namespace std;

class queue{
	public:
	Node * top;
	ll l1;
	queue(){
		top = NULL;
	}
	//pushes on the top
	void enqueue(int value){
		l1.insertat(1,value);
		//top= new_head;
		top = l1.head;
	}
	//pops on the top
	void dequeue(){
		l1.delet();
		top = l1.head;
	}

	bool isEmpty(){
		if(top == NULL) return true;
		return false;
	}
	void size(){
		l1.ci();
	}
	void topdisplay(){
		cout<<top<<endl;
	}
	void display(){
		l1.display();
	}
};

int main(){
	queue s1;
	
	int a,b;
	cout<<"number of inputs"<<endl;
	cin>>a;
	cout<<"give me the numbers"<<endl;
	for(int i=1;i<a+1;i++){
		cin>>b;
		s1.enqueue(b);
	}
	cout<<endl;
	s1.size();
	s1.display();
	s1.dequeue();
	s1.display();
	s1.dequeue();
	s1.display();
	s1.dequeue();
	s1.display();
	//s1.dequeue();
	//s1.display();
	//s1.dequeue();
	//s1.display();
	cout<<endl;
return 0;
}
