#include <iostream>
// #define ll long long;

int numPaths(int n,int m);

using namespace std;

int main() {
	int i,T,n,m;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> n >> m;
	    cout << numPaths(n,m) << endl;
	}
	return 0;
}
int numPaths(int n,int m){
    long long c[n][m];
    int i,j;
    for(i=0;i<n;i++)
        c[i][0]=1;
    for(j=0;j<m;j++)
        c[0][j]=1;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
            c[i][j]=(c[i-1][j]+c[i][j-1])%(1000000000+7);
    return c[n-1][m-1];
}