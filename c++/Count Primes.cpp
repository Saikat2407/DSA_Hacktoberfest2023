//Leetcode Count Primes Problem (Used Sieve of Eratosthenes)
//Link: https://leetcode.com/problems/count-primes/
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool>v(n,true);
        for(int i=2;i<n;i++)
        {
            if(v[i]==true)
            {
                for(int j=2*i;j<n;j+=i)
                {
                    v[j]=0;
                }
                count++;
            }
        }
        return count;
    }
};