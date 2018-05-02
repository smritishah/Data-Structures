#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap{
	
	int *harr;
	int capacity;
	int heap_size;
	
	public: MinHeap(int cap);
	
	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return (2*i+1);
	}
	int right(int i){
		return (2*i+2);
	}
	int extractMin();
	
	void insertKey(int k);
};

MinHeap::MinHeap(int cap){
	heap_size = 0;
	capacity = cap;
	harr = new int[capacity];
}
int MinHeap::extractMin(){
	if(heap_size<=0)
		return INT_MAX;
	if (heap_size==1){
		heap_size--;
		return harr[0];
	}
	else return harr[0];
}
void MinHeap::insertKey(int k){
	if(heap_size==capacity){
		cout << "Overflow" << endl;
		return;
	}else{
		heap_size++;
		int i = heap_size-1;
		harr[i]=k;
		
		while(i>=0 && harr[parent(i)]>harr[i]){
			swap(&harr[i],&harr[parent(i)]);
			i = parent(i);
		}
	}
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	// your code goes here
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(21);
	cout << h.extractMin() << endl;
}