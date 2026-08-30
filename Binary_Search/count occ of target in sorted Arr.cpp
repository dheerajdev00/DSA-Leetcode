class Solution {
public:


    int FirstOccurance(vector<int> &nums, int n, int x){
        int first=-1;
        int s=0,e=n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==x){ //not >= bec for > ele also it will store in ans although x is not present
                first = mid;
                e=mid-1;
            }
            else if(nums[mid] > x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return first;
    }

    int LastOccurance(vector<int> &nums, int n, int x){
        int last=-1;
        int s=0,e=n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==x){
                last = mid;
                s=mid+1;
            }
            else if(nums[mid] > x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return last;
    }

    int countOccurrences(vector<int>& arr, int target) {
        int first = FirstOccurance(arr,arr.size(),target);
        int last = LastOccurance(arr,arr.size(),target);
        return last-first+1; //if none of them are -1
    }
}; 