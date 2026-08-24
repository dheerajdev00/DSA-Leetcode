class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        int src = 0; //in this case it is 0
        vector<int> Adj[N];
        //mat to list
        for(auto it : edges){
            Adj[it[0]].push_back(it[1]);
            Adj[it[1]].push_back(it[0]);
        }

        int dist[N];
        for(int i=0; i<N; i++){
            dist[i] = 1e9;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : Adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it] = 1+dist[node];
                    q.push(it);
                }
            }
        }

        vector<int> ans(N,-1); //if node not reachable it shd be -1
        for(int i=0; i<N; i++){
            if(dist[i]!=1e9){
                ans[i] = dist[i];
            }
        }
        return ans;


    }
};
