class Solution{
public:
    
    bool detect(int src, vector<int>adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q; //{node,parent}
        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjnode : adj[node]){
                if(!vis[adjnode]){ //if not visited then visit and push along with parent
                    vis[adjnode] = 1;
                    q.push({adjnode,node});
                }
                else if(parent != adjnode){   //visited and parent != adjnode ...therefore cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){ //check for all connected component
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};