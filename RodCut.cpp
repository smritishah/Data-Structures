#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxNum(int L,int N,int l[],int p[]);
int max(int a,int b);

int main() {
	int T,i,L,N=3,j;
	cin >> T;
	for (i=0;i<T;i++) {
	    cin >> L; // >> N;
	    int l[N],p[N];
	    for(j=0;j<N;j++)
	        p[j]=1;
	    for(j=0;j<N;j++)
	        cin >> l[j];
	    // had prices been different
	    // for(j=0;j<N;j++)
	    //     cin >> p[j];
	    cout << maxNum(L,N,l,p) << endl;
	}
	return 0;
}
int maxNum(int L,int N,int l[],int p[]) {
    int arr[N][L+1];
    sort(l,l+N);
    int i,j;
    // filling 0th column of matrix
    for(i=0;i<N;i++)
        arr[i][0]=0;
    // filling 1st row of matrix
    for(j=1;j<L+1;j++){
        if(j%l[0]==0)
            arr[0][j]=p[0]*(j/l[0]);
        else
            arr[0][j]=0;
    }
    // filling the remaining matrix
    for(i=1;i<N;i++){
        for(j=1;j<L+1;j++){
            if(l[i]>j) // || j%l[i]!=0)
                arr[i][j]=arr[i-1][j];
            else if (arr[i][j-l[i]]==0 && j%l[i]!=0 &&  arr[i-1][j]==0)
                arr[i][j]=0;
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-l[i]]+p[i]);
        }
    }
    // printing the arr
    // for(i=0;i<N;i++){
    //     for(j=0;j<=L;j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    return arr[N-1][L];
}
int max(int a,int b){
    return a>b?a:b;
}