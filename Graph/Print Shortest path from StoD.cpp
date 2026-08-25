/* THIS IS FOR PRINTING SHORTEST PATH FROM SOURCE TO DESTINATION
  HERE source = s, destination = n  where n=no of nodes
*/

class Solution{
public:
    vector<int> PrintShortestPath(vector<vector<int>> &edges, int n, int S) {
        //make adj list
        vector<pair<int, int>> Adj[n+1]; //Adj[0] is a vector and each ele is a pair
        for(auto it : edges){
            Adj[it[0]].push_back({it[1],it[2]});
            Adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;

        dist[1] = 0; //source =1 ... and it is 1 based indexing
        pq.push({0,1});

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for(auto it : Adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis+wt < dist[adjNode]){
                    dist[adjNode] = dis+wt;
                    pq.push({dis+wt,adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        //now get the path from parent
        if(dist[n] == 1e9) return {-1}; //if we didnt reach the destination return -1
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;

    }
};