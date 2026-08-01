class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            res.push_back({nums[i],i});
        }

        sort(res.begin(), res.end());

        int l=0,r=n-1;

        while(l<r){
            int sum = res[l].first+res[r].first;
            if(sum == target){
                return {res[l].second, res[r].second};
            }
            else if(sum<target) l++;
            else r--;
        }
        return {};
    }
};