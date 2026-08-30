class Solution {
public:
    
    int Floor(vector<int> &nums, int x){
        int n = nums.size();
        int l=0, h=n-1;
        int ans = -1;

        while(l<=h){
            int mid = l+(h-l)/2;

            //maybe an ans
            if(nums[mid]<=x){
                ans = nums[mid];
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }

    int Ceil(vector<int> &nums, int x){
        int n = nums.size();
        int l=0, h=n-1;
        int ans = -1;

        while(l<=h){
            int mid = l+(h-l)/2;

            //maybe an ans
            if(nums[mid]>=x){
                ans = nums[mid];
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        return {Floor(nums,x),Ceil(nums,x)};
    }
};