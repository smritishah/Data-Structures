#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int maxSum(int arr[],int N);

int main() {
	int T,N,i,j;
	cin >> T;
	for (i=0;i<T;i++){
	    cin >> N;
	    int arr[N]={0};
	    for(j=0;j<N;j++)
	        cin >> arr[j];
	    cout << maxSum(arr,N) << endl;
	}
	return 0;
}
int maxSum(int arr[],int N){
    int i,currSum=arr[0],maxSum=arr[0];
    for(i=1;i<N;i++) {
        currSum = max(currSum+arr[i],arr[i]);
        if(currSum>maxSum)
            maxSum = currSum;
    }
    return maxSum;
}
int max(int a,int b) {
    return (a>b)?a:b;
}