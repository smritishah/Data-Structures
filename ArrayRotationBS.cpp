// finding min element in a rotated array using binary Search
// same can be used to find no. of rotations that has been done on a sorted array

#include <iostream>
using namespace std;

int minElement();

int main() {
	int T,i;
	cin >> T;
	for(i=0;i<T;i++)
	    cout << minElement() << endl;
	return 0;
}
int minElement(){
    int N,i;
    cin >> N;
    int arr[N];
    for(i=0;i<N;i++)
        cin >> arr[i];
    int m;
    int low=0,high=N-1;
    
    if(arr[low]<=arr[high])
        return arr[low];
    while(low<=high){
        if(low==high)
            return arr[low];
        else{
            m=(low+high)/2;
        if(arr[m]<arr[high])
            high=m;
        else
            low=m+1;
        }
    }
}