#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minOpr();
int min(int a,int b,int c);

int main() {
	int i,T;
	cin >> T;
	for(i=0;i<T;i++) {
	    cout << minOpr() << endl;
	}
	return 0;
}
int minOpr() {
    int l1,l2,i,j;
    cin >> l1 >> l2;
    string w1,w2;
    cin >> w1 >> w2;
    int W[l1+1][l2+1];
    // filling 1st row
    for(j=0;j<=l2;j++)
        W[0][j]=j;
    // filling 1st column
    for(i=0;i<=l1;i++)
        W[i][0]=i;
    // filling the remaining matrix
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(w1[i-1]==w2[j-1])
                W[i][j]=W[i-1][j-1];
            else
                W[i][j]=min(W[i-1][j-1],W[i][j-1],W[i-1][j])+1;
        }
    }
    // printing the matrix
    // for(i=0;i<=l1;i++){
    //     for(j=0;j<=l2;j++)
    //         cout << W[i][j] << " ";
    //     cout << endl;
    // }
    return W[l1][l2];
}
int min(int a,int b,int c) {
    return a<b?(a<c?a:c):(b<c?b:c);
}