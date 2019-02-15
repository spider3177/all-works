#include <iostream>
#include "ll.cpp"
using namespace std;

class stack{
	public:
	Node * top;
	ll l1;
	stack(){
		top = NULL;
	}
	//pushes on the top
	void push(int value){
		l1.insertat(1,value);
		//top= new_head;
		top = l1.head;
	}
	//pops on the top
	void pop(){
		l1.deleteat(1);
		top = l1.head;
	}

	bool isEmpty(){
		if(top == NULL) return true;
		return false;
	}
	int size(){
		l1.ci();
	}
	void topdisplay(){
		cout<<top->data<<endl;
	}
	void display(){
		l1.display();
	}
};

int main(){
	stack s1;
	
	int a,b;
	cout<<"number of inputs"<<endl;
	cin>>a;
	cout<<"give me the numbers"<<endl;
	for(int i=1;i<a+1;i++){
		cin>>b;
		s1.push(b);
	}
	cout<<endl;
	s1.display();
	cout<<"pop : "<<endl;
	s1.pop();
	s1.display();
	cout<<"topdisplay : "<<endl;
	s1.topdisplay();
	s1.display();
	cout<<"size : "<<endl;
	s1.display();
	cout<<endl;
return 0;
}
