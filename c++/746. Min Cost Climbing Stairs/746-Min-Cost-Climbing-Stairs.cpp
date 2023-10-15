// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int solve(vector<int>& cost, int n){
                
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr = 0;

        for(int i = 2; i < n; i++){
            curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve(cost, n);
        return ans;
    }
};

/*
Here's a breakdown of the code:

1. The solve function is a helper function that calculates the minimum cost to reach the n-th step of the staircase. It takes an array cost and the total number of steps n as its parameters.

2. Inside the solve function, there are three variables:

prev2: Represents the minimum cost to reach the (i-2)-th step.
prev1: Represents the minimum cost to reach the (i-1)-th step.
curr: Represents the minimum cost to reach the i-th step, which is calculated by adding the cost of the current step to the minimum of prev1 and prev2.

3. The for loop iterates from the 2nd step (i = 2) to the n-th step. In each iteration, it updates the prev2, prev1, and curr variables to calculate the minimum cost for the current step.

4. Finally, the minCostClimbingStairs function is the entry point. It calculates the total number of steps n as the size of the cost array and calls the solve function to find the minimum cost to reach the top of the staircase.

5. The result is returned as ans, which represents the minimum cost, and this value is returned as the final result.
*/