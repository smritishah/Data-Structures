#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lis(int arr[],int N);
int max(int c[],int N);
int maxVal(int a,int b);

int main() {
	int T,i,N,j;
	cin >> T;
	for (i=0;i<T;i++) {
	    cin >> N;
	    int arr[N];
	    for (j=0;j<N;j++)
	        cin >> arr[j];
	    cout << lis(arr,N) << endl;
	}
	return 0;
}
int lis(int arr[],int N) {
    int c[N];
    int i,j;
    for(i=0;i<N;i++)
        c[i]=1;
    for(i=1;i<N;i++){
        for(j=0;j<i;j++){
            if(arr[j]<arr[i])
                c[i]=maxVal(c[i],c[j]+1);
        }
    }
    return max(c,N);
}
int max(int c[],int N) {
    int m=0;
    for(int i=0;i<N;i++){
        if(c[i]>m)
            m=c[i];
    }
    return m;
}
int maxVal(int a,int b) {
    return a>b?a:b;
}
