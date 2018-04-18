#include <iostream>
using namespace std;

int substringLen(string w1, string w2, int l1,int l2);

int main() {
	int i,T,l1,l2;
	cin >> T;
	for(i=0;i<T;i++){
	    cin >> l1 >> l2;
	    string w1,w2;
	    cin >> w1;
	    cin >> w2;
	    cout << substringLen(w1,w2,l1,l2) << endl;
	}
	return 0;
}
int substringLen(string w1, string w2, int l1,int l2){
    int c[l1+1][l2+2];
    int i,j,max=0;
    for(i=0;i<=l1;i++)
        for(j=0;j<=l2;j++)
            c[i][j]=0;
    for(i=1;i<=l1;i++)
        for(j=1;j<=l2;j++)
            if(w1[i-1]==w2[j-1])
                c[i][j]=c[i-1][j-1]+1;
    // iterating through the matrix to find the max value
    for(i=1;i<=l1;i++)
        for(j=0;j<=l2;j++)
            if(c[i][j]>max)
                max=c[i][j];
    return max;
}