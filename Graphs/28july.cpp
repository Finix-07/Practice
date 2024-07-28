#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>

#include <queue>

using namespace std;
#define P pair<int,int>
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    

    unordered_map<int, vector<int>> adj;

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // make list

    vector <int> d1(n+1, INT_MAX); // this store the min in dijk
    vector <int> d2(n+1, INT_MAX); // this store 2nd min

    
    priority_queue<P, vector<P>, greater<P>> pq; 
    pq.push({0,1}); // initial position
    
    d1[1] = 0; // time for initial
    
    while(!pq.empty()){
        auto [timePassed, node] = pq.top();
        pq.pop();
        if(node == n && d2[n] != INT_MAX){ // if node is the req one, and we have found a value for the 2nd max
            return d2[n];
        }
        int div = timePassed/change; 
        if(div % 2 == 1){// odd
            timePassed = change*(div+1); // to jump to next moving time
        } 
        for (auto &neighbor : adj[node]){
            if(d1[neighbor] > timePassed+time){ // normal dijkstra but keep maintaining the 2nd min too
                d2[neighbor] = d1[neighbor];
                d1[neighbor] = timePassed + time;
                pq.push({timePassed+time , neighbor}); 
            }
            else if (d2[neighbor] > timePassed + time && d1[neighbor] != timePassed + time){ // updating only the 2nd min cost vector
                d2[neighbor] = timePassed + time;
                pq.push({timePassed + time, neighbor});
            }
        }
    }

    return -1;

}


int main(){

    int n =5;
    vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    int time = 3;
    int change = 5;

    cout << "The Min time cost is: ";

    cout << secondMinimum(n, edges, time,change);

    return 0;
}