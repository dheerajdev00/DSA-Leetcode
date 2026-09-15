class Solution {
public:

    int cntStu(vector<int> &arr, int pages){
        int students = 1;
        long long PgstoOneStu = 0;
        for(int i=0; i<arr.size(); i++){
            if(PgstoOneStu + arr[i] <= pages){
                PgstoOneStu += arr[i];
            }
            else{
                students += 1;
                PgstoOneStu = arr[i];
            }
        }
        return students;
        
    }

    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        if(m>n) return -1;
        
        int low = *max(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            int students = cntStu(nums,mid);
            if(students > m){
                low = mid+1; //increase the threshold s.t. one stu get more books to reduce no of stu
            }
            else{
                high = mid-1; //since want min
            }
        }
        return low;
    }
};