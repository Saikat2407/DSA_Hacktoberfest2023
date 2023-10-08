// Leetcode problem
// https://leetcode.com/problems/zigzag-conversion/

public class Candy {
    public int candy(int[] ratings) {
        int candyV[] = new int[ratings.length];
        int candyV2[] = new int[ratings.length];
        int s=0;
        for(int i=0;i<candyV.length-1;i++){
            if(ratings[i]<ratings[i+1]){
                candyV[i+1]=candyV[i]+1;
            }
        }
        for(int i=candyV2.length-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candyV2[i-1]=candyV2[i]+1;
            }
        }
        for(int i=0;i<ratings.length;i++){
            s=s+Math.max(candyV[i]+1,candyV2[i]+1);
        }
        return s;
    }
}
