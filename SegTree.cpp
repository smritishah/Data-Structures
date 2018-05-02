#include <bits/stdc++.h>
using namespace std;

class SegmentTree {

	int n;
	int *data;
	
	// constructor when only size of array is given
	public: SegmentTree(int size){
		n = size;
		data = new int[2*n];
	}

	// constructor when set of values is given
	public: SegmentTree(int arr[]){
		n = sizeof(arr)/sizeof(arr[0]);
		// n=5;
		data = new int[2*n];
		for(int i=0;i<n;i++)
			data[i+n] = arr[i];
		for(int idx = n-1;idx>0;idx--)
			data[idx]=min(data[2*idx],data[2*idx+1]);
		// printing elements of data
		for(int i=1;i<2*n;i++)
			cout << data[i] << endl;
		cout << "end of elements" << endl;
	}

	void update(int idx, int value){
		idx += n;
		data[idx] = value;
		while(idx>1){
			idx /= 2;
			data[idx]=min(data[idx*2],data[idx*2+1]);
		}
	}

	int minimum(int left,int right){
		int res = INT_MAX;
		left += n; right += n;
		
		while(left<right){
			if(left%2!=0)
				res = min(res,data[left++]);
			if(right%2!=0)
				res = min(res,data[--right]);
			left /= 2; right /= 2;
		}
		return res;
	}
	
};	// end of class

int main() {
	// your code goes here
	// SegmentTree st ( 5 );
	// st. update ( 0 , 5 );
	// st. update ( 1 , 2 );
	// st. update ( 2 , 3 );
	// st. update ( 3 , 1 );
	// st. update ( 4 , 4 );
	// int temp[] = {5,2,3,1,4};
	// int temp[] = {1,5,3,7,3,6,5,7};
	int temp[] = {1,2,3,4,5};
	SegmentTree st(temp);
	
	std :: cout << "" << st. minimum ( 1 , 4 ) << std :: endl;
	st. update ( 3 , 10 );
	std :: cout << "" << st. minimum ( 1 , 4 ) << std :: endl;
	std :: cout << "" << st. minimum ( 0 , 5 ) << std :: endl;
	st. update ( 4 , 0 );
	std :: cout << "" << st. minimum ( 1 , 4 ) << std :: endl;
	std :: cout << "" << st. minimum ( 0 , 5 ) << std :: endl;

	//SegmentTree st2 ([ 5 , 2 , 3 , 1 , 4 ]);
	return 0;
}
