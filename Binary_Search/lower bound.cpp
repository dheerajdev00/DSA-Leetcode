class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int l=0, h=n-1;
        int ans = n;

        while(l<=h){
            int mid = l+(h-l)/2;

            //maybe an ans
            if(nums[mid]>=x){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};