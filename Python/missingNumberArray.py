class Solution:
    def missingNumber(self,array,n):
        array.sort()
        for i in range(array[0],array[-1]):
            if i not in array:
                return i
        return array[-1]+1
        