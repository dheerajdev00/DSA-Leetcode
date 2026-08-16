class Solution {
public:
    int maxSubArray(vector<int>& nums) { 

        //THIS FUN IS returning the max sum...but along with that we can also get the start and end index of subarray with max sum

        int n = nums.size();
        int subarray_start = -1, subarray_end = -1;
        int start = -1;

        int sum = 0, maxi=INT_MIN;

        for(int i=0; i<n; i++){
            if(sum==0) start = i;
            
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
                subarray_start = start, subarray_end = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};