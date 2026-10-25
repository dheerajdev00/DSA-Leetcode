class Solution{
	public:

        int MCM(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
            if(i==j){ // single matrix has 0 multiplication
                return 0;
            }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int res = (mini, MCM(i,k,nums,dp)+MCM(k+1,j,nums,dp)+(nums[i-1]*nums[k]*nums[j]));
                if(res < mini){
                    mini = res;
                }
            }
            return dp[i][j] = mini;
        }
        
        
		int matrixMultiplication(vector<int>& nums){
            int n = nums.size();

            vector<vector<int>> dp(n, vector<int>(n,-1));

            int ans = MCM(1,n-1,nums,dp);
            return ans;
    	}
};