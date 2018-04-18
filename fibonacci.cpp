#include <iostream>
using namespace std;

long long int fib (int n);
int main() {
	int T,N,i;
	cin >> T;
	for(i=1;i<=T;i++) {
	    cin >> N;
	    cout << fib(N) << endl;
	}
	return 0;
}

long long int fib (int n) {
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else {
        long long int fib[n]={0};
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=n;i++)
            fib[i]=(fib[i-1]+fib[i-2])%1000000007;
        return fib[n];
    }
}