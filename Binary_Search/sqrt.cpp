class Solution {
public:
    int floorSqrt(int n)  {
      int l=1, h=n;
      while(l<=h){
        long long mid = (l+h)/2;
        long long val = mid*mid;
        if(val<=n){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
      }
      return h;
    }
};