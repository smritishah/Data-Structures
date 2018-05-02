#include <bits/stdc++.h>
using namespace std;

class Fenwick {
	
	int size;
	int *arr;
	
	public: Fenwick(int n){
		size = n+1;
		arr = new int[size];
	}
	
	public: Fenwick(int data[]){
		// size = sizeof(data)/sizeof(data[0]);
		size = 8;
		arr = new int[size+1];
		
		// storing the values in array
		for(int i=1;i<size+1;i++)
			arr[i]=data[i-1];
			
		// storing the sum in array based on binary indices
		for(int idx=1;idx<size+1;idx++){
			int idx2 = idx + (idx & -idx);
			arr[idx2] += arr[idx];
		}
	}
	
	int calcSum(int idx){
		int res = 0;
		while (idx!=0){
			res += arr[idx];
			idx -= idx & -idx;
		}
		return res;
	}
	
	void update(int idx,int val){
		for(++idx;idx<size+1;idx += idx & -idx)
			arr[idx]+= val;
	}
	
	int sum(int l,int r){
		return calcSum(r)-calcSum(l-1);
	}
	
};

int main() {
	// your code goes here
	int temp[] = {1,2,3,4,5,6,7,8};
	Fenwick f(temp);
	//f.update(3,5);
	cout << f.sum(1,5);
	cout << f.sum(5,7);
	return 0;
}