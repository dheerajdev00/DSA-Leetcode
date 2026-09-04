class Solution {
public:
    
    bool canWePlace(vector<int> &arr, int mindist, int k){
        int cntCows = 1, last=arr[0];
        for(int i=0; i<arr.size(); i++){
            if(arr[i]-last >= mindist){
                cntCows++;
                last = arr[i];
            }
            if(cntCows >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int low = 1, high = nums[n-1]-nums[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canWePlace(nums,mid,k)){
                low = mid+1; //we want max mainimum dist so go right
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};