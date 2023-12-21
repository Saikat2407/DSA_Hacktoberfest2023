//374. Guess Number Higher or Lower
//https://leetcode.com/problems/guess-number-higher-or-lower/description/
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        //start=s, end=e
        int s=1;
        int e=n-1;
        while(s<=e){
            int m=s + (e-s)/2;
            if(guess(m)==0){
                return m;
            }else if(guess(m)== -1){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return n;
    }
}
