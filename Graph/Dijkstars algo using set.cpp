/* THIS IS DIJKSTRAS ALGO USING SET */

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> Adj[], int S) {

        set<pair<int, int>> st;
        vector<int> dist(V,1e9);

        st.insert({0,S}); //{dist,node}
        dist[S] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            //go to Adj list
            for(auto it : Adj[node]){
                int adjNode = it[0];
                int edgWt = it[1];

                if(dis+edgWt < dist[adjNode]){
                    //erase if it already exist
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis+edgWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;

    }
};