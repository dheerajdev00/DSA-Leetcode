class Solution{
    public:

    // FLOOD FILL USING DFS

    void dfs(int r, int c, vector<vector<int>> &image, int newColor,vector<vector<int>>&ans, int drow[], int dcol[], int inicol){
        ans[r][c] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicol && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,image,newColor,ans,drow,dcol,inicol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
      int inicolor = image[sr][sc];
      vector<vector<int>> ans = image;

      int drow[] = {-1,0,+1,0};
      int dcol[] = {0,+1,0,-1};
      dfs(sr,sc,image,newColor,ans,drow,dcol,inicolor);
      return ans;


    }
};