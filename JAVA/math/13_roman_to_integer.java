/*
"https://leetcode.com/problems/roman-to-integer/"
13. Roman to Integer ~ Easy
*/

class Solution {
    public int romanToInt(String s) {
        int nums[] = new int[s.length()];
        for(int i = 0; i < s.length(); i++){
            switch (s.charAt(i)){
                case 'M':
                    nums[i] = 1000;
                    break;
                case 'D':
                    nums[i] = 500;
                    break;
                case 'C':
                    nums[i] = 100;
                    break;
                case 'L':
                    nums[i] = 50;
                    break;
                case 'X' :
                    nums[i] = 10;
                    break;
                case 'V':
                    nums[i] = 5;
                    break;
                case 'I':
                    nums[i] = 1;
                    break;
            }
        }
        int sum = 0;
        for(int i = 0; i < nums.length - 1; i++){
            if (nums[i] < nums[i+1])
                sum -= nums[i];
            else
                sum += nums[i];
        }
        return sum + nums[nums.length-1];
    }
}
/**
 * Time Complexity: O(n), where n is the length of the input Roman numeral string.
 * Space Complexity: O(n), as we create an array to store the values of each character.
 */




// Single Pass Approach
class Solution {
    public int romanToInt(String s) {
        int ans = 0;

	// Iterate through the Roman numeral string from right to left
        for (int i = s.length()-1; i >= 0; i--) {
            int val = 0;

            switch(s.charAt(i)) {
                case 'I' : val = 1; break;
                case 'V' : val = 5; break;
                case 'X' : val = 10; break;
                case 'L' : val = 50; break;
                case 'C' : val = 100; break;
                case 'D' : val = 500; break;
                case 'M' : val = 1000;
            }

            if ( 4 * val < ans ) ans -= val;
            else ans += val;
        }

        return ans;
    }
}

/** 
 * --Intuition--
 * Roman Numeral Rules:
 * - IV represents 4, IX represents 9, XL represents 40, XC represents 90, CD represents 400, and CM represents 900.
 * - In these subtractive cases, the first numeral (I, X, or C) can be 5 or 10 times the second numeral (V, L, or D).
 * - General rule: We subtract when 4 times the current value is less than the accumulated result.
 *
 * We can also prove that we can put (3 * val < ans) if we work the other way around:
 * e.g. take 38 = XXXVIII
 * assume we have traversed till X|XXVIII from the ri8 and calculated ans = 28.
 * now for this last X: (3 * X) > (ans=28)
 * i.e. 30 > 28, right?
 * Now, we know we need to add this X=10 to get ans = 30.
 * which means we should only subtract if the 3 * first < second.
 * This is one of the extreme case where the difference between 3 * first and second is just 2. In all other cases, the difference will only get large. ie 3 * first << second.
 *
 * Time Complexity: O(n), where n is the length of the input Roman numeral string.
 * Space Complexity: O(1).
 */