#include <iostream>
using namespace std;

long long int bicoeff(int n,int r);
int min(int a, int b);
int main() {
	int T,n,r,i;
	cin >> T;
	for (i=0;i<T;i++) {
	    cin >> n >> r;
	    cout << bicoeff(n,r) << endl;
	}
	return 0;
}
long long int bicoeff(int n,int r) {
    long long int C[n+1][r+1]={0};
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,r);j++) {
            if(j==0 || j==i)
                C[i][j]= 1;
            else
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%(1000000000+7);
        }
    }
    return C[n][r];
}
int min(int a, int b)
{
    return (a<b)? a: b;
}