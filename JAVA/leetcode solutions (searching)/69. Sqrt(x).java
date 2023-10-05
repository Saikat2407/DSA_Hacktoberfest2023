/*69. Sqrt(x) 
https://leetcode.com/problems/sqrtx/
  */

class Solution {
    public int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int start=1;
        int end=x;
        int result=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            long square=(long)mid*mid;

            if(square == x){
                return mid;
            }else if(square < x){
                start=mid+1;
                result = mid;
            }else{
                end=mid -1;
            }
        }
        return result;
    }
}
