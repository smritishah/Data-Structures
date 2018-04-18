#include <iostream>

#define ll long long

using namespace std;

ll maxSum(int arr[],int N);
ll max(ll a,ll b);

int main() {
	int i,j,T,N;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> N;
	    int arr[N];
	    for(j=0;j<N;j++)
	        cin >> arr[j];
	    cout << maxSum(arr,N) << endl;
	}
	return 0;
}
ll maxSum(int arr[],int N){
    ll sum[N];
    int seq[N];
    int i,j;
    for(i=0;i<N;i++){
        sum[i]=arr[i];
        seq[i]=i;
    }
    for(i=1;i<N;i++){
        for(j=0;j<i;j++){
            if(arr[j]<arr[i]){
                sum[i]=max(sum[i],sum[j]+arr[i]);
                if(sum[i]==sum[j]+arr[i])
                    seq[i]=j;
            }
        }
    }
    // find the max sum in this array
    ll maxs = sum[0];
    for(i=1;i<N;i++)
        if(maxs<sum[i])
            maxs=sum[i];
    return maxs;
}
ll max(ll a,ll b){
    return a>b?a:b;
}