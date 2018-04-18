#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int max2(long long int a,long long int b);
long long int max3(long long int a,long long int b,long long int c);

int main() {
	int T,i,N,j,k;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> N;
	    if (N==0){
	        cout << 0 << endl;
	        continue;
	    }
	    int arr[N][N];
	    for(j=0;j<N;j++)
	        for(k=0;k<N;k++)
	            cin >> arr[j][k];
	    long long int c[N][N];
	    for(j=0;j<N;j++)
	        c[0][j]=arr[0][j];
	    for(j=1;j<N;j++){
	        // for 1st element of row
	        c[j][0]=max2(c[j-1][0],c[j-1][1])+arr[j][0];
	        // for last element of row
	        c[j][N-1]=max2(c[j-1][N-1],c[j-1][N-2])+arr[j][N-1];
	        // for mid elements
	        for(k=1;k<N-1;k++)
	            c[j][k]=max3(c[j-1][k-1],c[j-1][k],c[j-1][k+1])+arr[j][k];
	    }
	    // finding max of last row
	    long long int maxCost = c[N-1][0];
	    for(j=1;j<N;j++)
	        if(maxCost<c[N-1][j])
	            maxCost = c[N-1][j];
	    cout << maxCost << endl;
	}
	return 0;
}
long long int max2(long long int a,long long int b){
    return a>b?a:b;
}
long long int max3(long long int a,long long int b,long long int c){
    return a>b?(a>c?a:c):(b>c?b:c);
}