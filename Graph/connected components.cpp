class Solution {
  public:

    void DFS(vector<int> Adj[], int vis[], int node){
        vis[node] = 1;
        for(auto it : Adj[node]){
            if(!vis[it]){
                DFS(Adj,vis,it);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> AdjList[V];

        //TO CHANGE ADJACENCY MATRICX TO ADJACENCY LIST
        for(auto edge : edges){ //we cannot use two loop bec here each ele of matrix represent edge
            int u = edge[0];
            int v = edge[1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(v);
        }

        int cnt=0;
        int visited[V] = {0};

        for(int i=0; i<V; i++){
            if(!visited[i]){
                cnt++;
                DFS(AdjList,visited,i);
            }
        }
        return cnt;
    
    }
};