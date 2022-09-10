#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n, m, src;
    cin>>n;
    cin>>m;

    vector<pair<int, int>> adj[n+1];

    int u, v, w;
    for(int i = 0; i < m; i++){

        cin>>u;
        cin>>v;
        cin>>w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    cin>>src;   

    
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
    vector<int> dist(n+1, INT_MAX); 

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()){

        int distance = pq.top().first;        
        int prev = pq.top().second;
        pq.pop();

        for(auto it : adj[prev]){
            
            int next = it.first;
            int next_dist = it.second;

            if(dist[next] > distance + next_dist){
                dist[next] = distance + next_dist;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    for(int i = 1; i <= n; i++) cout<<"("<<src<<"-"<<i<<"): "<<dist[i]<<endl;
    cout<<endl;
 
    return 0;
}