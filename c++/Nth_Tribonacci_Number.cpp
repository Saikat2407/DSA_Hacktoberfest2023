//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int t[38];
    int find(const int& n) {
        if(n == 0)           return 0;
        if(n == 1 || n == 2) return 1;
        if(t[n] != -1)       return t[n];
        
        t[n-1] = t[n-1] == -1 ? find(n-1) : t[n-1];
        t[n-2] = t[n-2] == -1 ? find(n-2) : t[n-2];
        t[n-3] = t[n-3] == -1 ? find(n-3) : t[n-3];
        
        return t[n] = t[n-1]+t[n-2]+t[n-3];
    }
    int tribonacci(int n) {
        memset(t, -1, sizeof(t));
        
        return find(n);
    }
};
