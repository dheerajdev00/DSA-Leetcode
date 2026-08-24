class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        vector<vector<int>> Adj[V];
        //mat to list
        for(auto it : edges){
            Adj[it[0]].push_back({it[1], it[2]});
            Adj[it[1]].push_back({it[0], it[2]});
        }

        //declare pq
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++){
            dist[i] = 1e9;
        }

        dist[S] = 0;
        pq.push({0,S}); //{dist,node}

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : Adj[node]){
                int Adjnode = it[0];
                int edgeWeight = it[1];

                if(dis+edgeWeight < dist[Adjnode]){
                    dist[Adjnode] = dis+edgeWeight;
                    pq.push({dist[Adjnode], Adjnode});
                }
            }
        }

        return dist;

    }
};