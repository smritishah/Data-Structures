#include <bits/stdc++.h>

using namespace std;

int main(){
   /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int V = 4,k,i,j;
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    
    int sol[V][V];
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            sol[i][j]=graph[i][j];
    
    // logic for transitiveClosure
    for(k=1;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++)
                sol[i][j] = sol[i][j] || (sol[i][k] && sol[k][j]);
        }
    }
    
    // printing sol
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}