#User function Template for python3

class Solution:
    #Function to check if two arrays are equal or not.
    def check(self,A,B,N):
        A.sort()
        B.sort()
        for i in range(N):
            if A[i]!=B[i]:
                return 0
        return 1
        