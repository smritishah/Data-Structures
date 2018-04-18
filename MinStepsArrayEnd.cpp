#include <iostream>
using namespace std;

int minSteps(int arr[],int N); 
int min(int a,int b);

int main() {
	int i,T,N,j;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> N;
	    int arr[N];
	    for(j=0;j<N;j++)
	        cin >> arr[j];
	    cout << minSteps(arr,N) << endl;
	}
	return 0;
}
int minSteps(int arr[],int N) {
    int num[N],jumps[N];
    num[0]=0;
    int i,j;
    for(i=1;i<N;i++)
        num[i]=N+1;
    for(i=1;i<N;i++){
        for(j=0;j<i;j++) {
            if(i<=j+arr[j]){
                num[i]=min(num[i],num[j]+1);
                if (num[i]==num[j]+1)
                    jumps[i]=j;
            }
        }
    }
    if(num[N-1]!=N+1)
        return num[N-1];
    else
        return -1;
}
int min(int a,int b){
    return a<b?a:b;
}