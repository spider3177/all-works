//first include the library
#include <iostream>
using namespace std;
//swapping function
void swap(int* a, int* b){
	int i;
	i = *a;
	*a = *b;
	*b = i;
}
	



//making the partition and arranging the array
int partition(int arr[],int l,int h){
	int pivot = arr[h];
	int x= (l-1);
	for (int a=l;a<h;a++){	
		if (arr[a] <= pivot){
			x++;
			swap(&arr[x],&arr[a]);
		}
	}
	swap(&arr[x+1],&arr[h]);
return x+1;
}
//use of quicksort and the recursion within it
void quicksort( int arr[], int low, int high){
	if (low<high){
	int p = partition(arr,low,high);
	quicksort(arr,low,p-1);//rearrangement before the pivot
	quicksort(arr,p+1,high);//rearrangement after the pivot
	}
}


//the main function
int main(){
	int a;
	cout<<"give the number of elements"<<endl;
	cin>>a;
	int arr[a];
	int c;
	cout<<"Add the elements of the array here"<<endl;	
	for(int i=0;i<a;i++){
		cin>>c;
		arr[i]=c;
	}
	quicksort(arr,0,a-1);
	cout<<endl;
	for(int j=0;j<a;j++){
	cout<<arr[j]<<endl;
	}
	
}
