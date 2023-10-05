//  https://practice.geeksforgeeks.org/batch/gc-tutorials-dsa/track/PC-W1-R/problem/game-of-death-in-a-circle1840
/*
There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

Example 1:

Input:
n = 2, k = 1
Output:
2
Explanation:
Here, n = 2 and k = 1, then safe position is
2 as the person at 1st position will be killed.

 */

 // Solution -
 class Solution {
    
    // Function to find the position of the last remaining person in the Josephus problem
    static int josephus(int n, int k) {
        if (n == 1)
            return 1;
        else
            /*
             * The position returned by josephus(n - 1, k) is adjusted because the
             * recursive call josephus(n - 1, k) considers the original position
             * k%n + 1 as position 1
             */
            return (josephus(n - 1, k) + k-1) % n + 1;
    }
    
    // Function to find the safe position in the Josephus problem
    static int safePos(int n, int k) {
        return josephus(n,k);
    }
}