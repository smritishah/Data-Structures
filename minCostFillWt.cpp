#include <iostream>
#define INF 100000
using namespace std;

long long int minCost(int arr[],int N,int W,int size);
int min(int a,int b);

int main() {
	int T,i,N,W,j,size=0;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> N >> W;
	    int arr[N];
	    size=0;
	    for(j=0;j<N;j++){
	        cin >> arr[j];
	        if(arr[j]!=-1)
	            size++;
	    }
	    cout << minCost(arr,N,W,size) << endl;
	}
	return 0;
}
long long int minCost(int arr[],int N,int W,int size){
    int wt[size],val[size];
    int i,c=0,j;
    for(i=0;i<N;i++){
        if(arr[i]!=-1){
            wt[c]=i+1;
            val[c++]=arr[i];
        }
    }
    N=size;
    int dp[N+1][W+1];
    // initializing array to 0
    for(i=0;i<N+1;i++)
        for(j=0;j<W+1;j++)
            dp[i][j]=0;
    
    // initializing first column as INF
    for(i=0;i<W+1;i++)
        dp[0][i]=INF;
        
    // filling dp matrix
    for(i=1;i<N+1;i++){
        for(j=1;j<W+1;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else 
                dp[i][j]=min(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
        }
    }
    return (dp[N][W]>=INF)?-1:dp[N][W];
}
int min(int a,int b){
    return (a<b)?a:b;
}