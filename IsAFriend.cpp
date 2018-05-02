#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
	
	int *rank;
	int *parent;
	int n;
	
	public:DisjointSetUnion(int num){
		n = num;
		rank = new int[n];
		parent = new int[n];
		makeSet();
	}
	
	void makeSet(){
		for(int i=0;i<n;i++){
			rank[i]=0;
			parent[i]=i;
		}
	}
	int find(int x){
		if(parent[x]!=x){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}
	void unionn(int x,int y){
		int xroot = find(x);
		int yroot = find(y);
		if(rank[xroot]<rank[yroot]){
			parent[xroot]=yroot;
		}
		else if(rank[yroot]<rank[xroot]){
			parent[yroot]=xroot;
		}else{
			parent[yroot]=xroot;
			rank[xroot] += 1;
		}
	}
};

int main() {
	DisjointSetUnion dus(5);
	dus.unionn(0,2);
	dus.unionn(4,2);
	dus.unionn(3,1);
	
	if(dus.find(4)==dus.find(0))
		cout << "4 and 2 are friends" << endl;
	else
		cout << "4 and 2 are not friends" << endl;
		
	if(dus.find(1)==dus.find(0))
		cout << "1 and 0 are friends" << endl;
	else
		cout << "1 and 0 are not friends" << endl;
	return 0;
}