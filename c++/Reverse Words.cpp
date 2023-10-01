//Code, Leetcode QUES with Explanation
// Problem Link: 
// https://leetcode.com/problems/reverse-words-in-a-string-iii/solutions/4113212/c-easy-o-n/?envType=daily-question&envId=2023-10-01
class Solution {
public:
    string reverseWords(string s) {
        int start_of_word=0,end_of_word=0;
        for(end_of_word;end_of_word<s.length();end_of_word++)
            if(s[end_of_word]==' '){
                reverse(s.begin()+start_of_word,s.begin()+end_of_word);
                start_of_word=end_of_word+1;
            }
        reverse(s.begin()+start_of_word,s.begin()+end_of_word);
        return s;
    }
};


/*
Intuition
We can solve this problem by running a loop from0 to s.length()-1 and reversing each word. We can use the reverse() function and maintain two pointers start_of_word and end_of_word. On encountring the " ", reverse the word from start_of_word to end_of_word and update value of start_of_word to end_of_word+1.

Approach
Take two variables start_of_word and end_of_word with initial values of 0 for both. Run a loop from 0 to s.length()-1, if there is a space character i.e. s[end_of_word]==' ' then we will reverse the string from start_of_word to end_of_word and update the value of start_of_word to end_of_word+1. After completing the all words of string s has been reversed except the last one. so we will again reverse the string form start_of_word to end_of_word ans then simply return strings.

Complexity
Time complexity:
O(n)

Space complexity:
O(1)
*/
