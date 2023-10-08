class Solution:
    def duplicates(self, arr, n): 
    	#find the frequency of each element
        freq = [0]*n
        for i in range(n):
            freq[arr[i]]+=1
        #find the elements with frequency greater than 1
        ans = []
        for i in range(n):
            if freq[i]>1:
                ans.append(i)
        #if no such element found, return -1
        if len(ans)==0:
            return [-1]
        #else return the list of elements
        return ans
        