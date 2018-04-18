#include<bits/stdc++.h>
using namespace std;

int lcs(char *w1,char *w2,int l1,int l2);
int max(int a,int b);
int main() {
	int T,i,l1,l2;
	cin >> T;
	for (i=0;i<T;i++) {
	    cin >> l1 >> l2;
	    char *w1,*w2;
	   // char w1[l1];
	   // char w2[l2];
	   w1=(char *)malloc(l1*sizeof(char));
	    w2=(char *)malloc(l2*sizeof(char));
	    cin >> w1;
	    cin >> w2;
	    cout << lcs(w1,w2,l1,l2) << endl;
	}
	return 0;
}

  
int lcs(char *w1,char *w2,int m,int n) {
    int L[m+1][n+1];
    int i,j;
    for (i=0;i<=m;i++) {
        for(j=0;j<=n;j++){
            if (i==0 || j==0)
                L[i][j]=0;
            else if(w1[i-1]==w2[j-1])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
}
int max(int a,int b) {
    return (a>b)?a:b;
}