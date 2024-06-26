class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;

         while(n!=0){

             if(n&1){
                 count = count + 1;
             }
            n = n>>1;
         }
         return count;
    }
};
//https://leetcode.com/problems/number-of-1-bits/description/
