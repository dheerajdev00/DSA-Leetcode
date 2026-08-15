class Solution {
public:

   int Merge(vector<int> &arr, int s, int mid, int e){
    vector<int> temp;

    int l = s; //starting index of left half
    int r = mid+1; //starting index of right half

    //storing ele in the temporary array in a sorted manner
    int cnt=0;
    while(l<=mid && r<=e){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{ //right is smaller
            // All remaining elements in left half
            // will form inversions with arr[r]
            temp.push_back(arr[r]);
            cnt += (mid-l+1);
            r++;
        }
    }

    //if ele on the left half are still left
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }

    //if ele on the right half are still left
    while(r<=e){
        temp.push_back(arr[r]);
        r++;
    }

    //transfering all ele from temp to array
    for(int i=s; i<=e; i++){
        arr[i] = temp[i-s];
    }

    return cnt;

   }

   int MergeSort(vector<int> &arr, int s, int e){
    int cnt=0;
    if(s>=e) return cnt; //return when goes out of bound
    int mid = (s+e)/2;

    cnt += MergeSort(arr,s,mid); //left half
    cnt += MergeSort(arr,mid+1,e); //right half
    cnt += Merge(arr,s,mid,e); //merging sorted half

    return cnt;
   }

   long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();
    return MergeSort(nums,0,n-1);
    }
};