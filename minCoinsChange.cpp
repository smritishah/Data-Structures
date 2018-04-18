#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minCoins(int M);
int min(int a,int b);

int main() {
    int T,i,M;
    cin >> T;
    for (i=0;i<T;i++){
        cin >> M;
        cout << minCoins(M) << endl;
    }
	return 0;
}
int minCoins(int M){
    int i,N,j;
    int den[M];
    for(i=0;i<M;i++)
        cin >> den[i];
    cin >> N;
    sort(den,den+M);
    int W[M][N+1];
    // filling the 0th column
    for(i=0;i<M;i++)
        W[i][0]=0;
    // filling the 1st row
    for(j=1;j<N+1;j++){
        if(j%den[0]==0)
            W[0][j]=j/den[0];
        else
            W[0][j]=N+1; // filling it with some large number
    }
    // filling the remaining matrix
    for(i=1;i<M;i++){
        for(j=1;j<N+1;j++){
            if(den[i]<=j)
                W[i][j]=min(W[i-1][j],1+W[i][j-den[i]]);
            else
                W[i][j]=W[i-1][j];
        }
    }
    // for(i=0;i<M;i++){
    //     for(j=0;j<N+1;j++)  
    //         cout << W[i][j] << " ";
    //     cout << endl;
    // }
    return W[M-1][N];
}
int min(int a,int b){
	return a<b?a:b;
}