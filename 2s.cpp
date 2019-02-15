#include<iostream>
#include "ll.cpp"
using namespace std;
class Stack{
    public:
    Node * top;
    ll l1;
    Stack(){
        top=l1.head;
    }
    //pushes at top
    void push(int value){
        // void insertAt(int pos, int value){
        l1.insertat(1,value);
        //top i snew head
        top = l1.head;
    }
    //delete at top
    void pop(){
        //void deleteat(int pos){
		l1.deleteat(1);
        //top = new head
        top=l1.head;
    }
    bool isEmpty(){
        if(top==NULL) return true;
        return false;
    }
    int topp(){
		return top->data;
	}
	void Display(){
        l1.display();
    }
};
class Queues{
    public:
    Stack s1;
	Stack s2;
	Node * back;
    Queues(){
    }
    //enqued at back
    void enqued(int value){
        // void insertAt(int pos, int value){
        s1.push(value);
        //top i snew head
       	back = s1.top;
    }
    //dequed at bottom
    /*void dequed(){
        //void deleteat(int pos){
           l1.deleteat(l1.count());
        //bottom=new tail
        tai=l1.tail;
    }*/
    void dequed(){
		if(s2.isEmpty()){
			while(!s1.isEmpty()){
				s2.push(s1.topp());
				s1.pop();
			}
		}
		int x=s2.topp();
		s2.pop();
		while(!s2.isEmpty()){
			s1.push(s2.topp());
			s2.pop();
		}
	//return x;
    }
    void Dispaly(){
        s1.Display();
    }
};
int main(){
    Queues q1;
	int a,b;
	cout<<"number of inputs"<<endl;
	cin>>a;
	cout<<"give me the numbers"<<endl;
    for(int i=0;i<a;i++){
		cin>>b;
		q1.enqued(b);
	}
	q1.Dispaly();
	q1.dequed();
	q1.Dispaly();
	q1.dequed();
	q1.Dispaly();
	q1.dequed();
	q1.Dispaly();
	q1.dequed();
	q1.Dispaly();
	q1.dequed();/*
	   q1.Dispaly();
	    cout<<q1.size()<<endl;
	   if( q1.isEmpty()==1)
			cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;*/
	    return 0;
	}
