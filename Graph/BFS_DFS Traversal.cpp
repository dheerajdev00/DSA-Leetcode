class Solution {
  public:

    void DFS(vector<int> Adj[], int vis[], int node, vector<int> &dfs){
        vis[node] = 1;
        dfs.push_back(node);
        // traverse all its neighbours
        for(auto it : Adj[node]){
            if(!vis[it]){
                DFS(Adj,vis,it,dfs);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        vector<int> AdjList[V];

        //TO CHANGE ADJACENCY MATRICX TO ADJACENCY LIST
        for(auto edge : edges){ //we cannot use two loop bec here each ele of matrix represent edge
            int u = edge[0];
            int v = edge[1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(v);
        }

        int visited[V] = {0};
        int start = 0; //start node
        vector<int>dfs;

        DFS(AdjList,visited,start,dfs);
        return dfs;

    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        vector<int> AdjList[V];

        //TO CHANGE ADJACENCY MATRICX TO ADJACENCY LIST
        //TO CHANGE ADJACENCY MATRICX TO ADJACENCY LIST
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(v);
        }

        int visited[V] = {0};
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int>bfs;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : AdjList[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};