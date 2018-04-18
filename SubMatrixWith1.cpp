#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSubMatrix(int n,int m,int **arr);
int min(int a,int b, int c);

int main() {
	int T,i,n,m,j,k;
	cin >> T;
	for(i=0;i<T;i++) {
	    cin >> n >> m;
	    int** arr = new int*[m];
	   // int arr[n][m];
	    for(j=0;j<n;j++)
	        for(k=0;k<m;k++) {
	            arr[i] = new int[n];
	            cin >> arr[j][k];}
	   // int max=0,i,j;
    //     int C[n][m];
    //     for(i=0;i<n;i++) {
    //         C[i][0]=arr[i][0];
    //         if(arr[i][0]==1)
    //             max=1;
    //     }
    //     for(j=0;j<m;j++) {
    //         C[0][j]=arr[0][j];
    //         if(arr[0][j]==1)
    //             max=1;
    //     }
    //     for(i=1;i<n;i++){
    //         for(j=1;j<m;j++){
    //             if(arr[i][j]==0)
    //                 C[i][j]=0;
    //             else {
    //                 C[i][j]=min(C[i-1][j-1],C[i-1][j],C[i][j-1])+1;
    //                 if(C[i][j]>max)
    //                     max=C[i][j];
    //             }
    //         }
    //     }
        // cout << max << endl;
	   cout << maxSubMatrix(n,m,arr) << endl;
	}
	return 0;
}
int maxSubMatrix(int n,int m,int **arr) {
    int max=0,i,j;
    int C[n][m];
    for(i=0;i<n;i++) {
        C[i][0]=arr[i][0];
        if(arr[i][0]==1)
            max=1;
    }
    for(j=0;j<m;j++) {
        C[0][j]=arr[0][j];
        if(arr[0][j]==1)
            max=1;
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(arr[i][j]==0)
                C[i][j]=0;
            else {
                C[i][j]=min(C[i-1][j-1],C[i-1][j],C[i][j-1])+1;
                if(C[i][j]>max)
                    max=C[i][j];
            }
        }
    }
    return max;
}
int min(int a,int b, int c) {
    return a<b?(a<c?a:c):(b<c?b:c);
}