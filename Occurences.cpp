#include <iostream>
using namespace std;

int freq(int arr[],int N,int key);
int getRightPosition(int arr[],int l,int r,int key);
int getLeftPosition(int arr[],int l,int r,int key);

int main() {
	int T,i,N,j,key;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> N >> key;
	    int arr[N];
	    for(j=0;j<N;j++)
	        cin >> arr[j];
	    cout << freq(arr,N,key) << endl;
	}
	return 0;
}
int freq(int arr[],int N,int key){
    int left = getLeftPosition(arr,-1,N-1,key);
    int right = getRightPosition(arr,0,N,key);
    
    return (arr[left] == key && key == arr[right])?
           (right - left + 1) : -1;
    
}
int getRightPosition(int arr[],int l,int r,int key){
    int m;
    while(r-l>1){
        m=(l+r)/2;
        if(arr[m]<=key)
            l=m;
        else
            r=m;
    }
    return l;
}
int getLeftPosition(int arr[],int l,int r,int key){
    int m;
    while(r-l>1){
        m=(l+r)/2;
        if(arr[m]>=key)
            r=m;
        else
            l=m;
    }
    return r;
}