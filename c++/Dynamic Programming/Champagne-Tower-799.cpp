/*
LeetCode 799 Champagne-Tower
Description:-We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.
Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)

Question Link :- https://leetcode.com/problems/champagne-tower/
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double r[101][101]={0.0};
        r[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(r[i][j] >=1 )
                {
                    r[i+1][j]+= (r[i][j]-1)/(2.0);
                    r[i+1][j+1]+= (r[i][j]-1)/(2.0);
                    r[i][j]=1;
                }
            }
        }
        return r[query_row][query_glass];
    }
};
