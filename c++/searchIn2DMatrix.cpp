// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r=matrix.size();
       int c=matrix[0].size();
       int rowIndex=0;
       int colIndex=c-1;
       while(rowIndex<r && colIndex>=0){
           int element=matrix[rowIndex][colIndex];
           if(element==target){
               return 1;
           }
           else if(element>target){
               colIndex--;
           }
           else{
               rowIndex++;
           }
       }
       return 0;
    }
};