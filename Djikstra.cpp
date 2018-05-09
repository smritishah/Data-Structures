#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{

    // unordered_map<int, list<pair<int,int>>> m;
    unordered_map<T, list<pair<T,int>>> m;
        public: void addedge(T u,T v,int dist,bool bidir=true){
    // public: void addegde(int u,int v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir)
            m[v].push_back(make_pair(u,dist));
    }
    
    void printGraph() {
        for(auto i: m){
            
            // printing the origin city name
            cout << i.first << ":->";
            for(auto j: i.second){
                cout << "(" << j.first << "," << j.second << ")" << "; "; 
            }
            cout << endl;
        }
    }
    
    void djikstra(T src) {
        unordered_map<T,int> dist;
        
        for(auto c:m){
            dist[c.first] = INT_MAX;
        }
        dist[src] = 0;
        
        set<pair<int,T>> s;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            
            auto p = *(s.begin());
            T city = p.second;
            
            int citydist = p.first;
            s.erase(s.begin());
            
            // iterate over neighbors of current node
            for(auto neighbor:m[city]){
                if(neighbor.second+citydist < dist[neighbor.first]){
                    
                    // in set or priority queue, updation is not directly possible,
                    // so remove old pair and insert new pair
                    // jis bhi node hum ja rhe hum
                    T dest = neighbor.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                        s.erase(f);
                        // s.erase(make_pair(dist[neighbor.first],neighbor.first));
                    s.insert(make_pair(neighbor.second + citydist,neighbor.first));
                    dist[neighbor.first] = neighbor.second + citydist;
                }      
            }
        }
        
        // printing the computed shortest distances
        for(auto d:dist){
            cout << d.first << " is located at a distance of " << d.second << endl;
        }
    }
};

int main() {
    cout<<"Hello World!";
    
    Graph<string> india;
    india.addedge("Amritsar","Delhi",1);
    india.addedge("Amritsar","Jaipur",4);
    india.addedge("Jaipur","Delhi",2);
    india.addedge("Jaipur","Mumbai",8);
    india.addedge("Bhopal","Agra",2);
    india.addedge("Mumbai","Bhopal",3);
    india.addedge("Agra","Delhi",1);
    
    india.printGraph();
    india.djikstra("Amritsar");
}