class Solution {
public:

    bool  dfs(int node, int parent, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,node,vis,adj)==true){
                    return true; //there is a cycle
                }
            }
            else if(adjnode != parent) return true;
        }
        return false;
    }

    bool Iscycle(int V, vector<vector<int>>& edges) {
        vector<int> Adj[numCourses];
        for(auto it : prerequisites){
            Adj[it[0]].push_back(it[1]); 
        }
        vector<int>vis(V,0);
        for(int i=1; i<=V; i++){
            if(!vis[i]){
               if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
        

    }
};