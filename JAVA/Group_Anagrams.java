//Leetcode Problem 49 Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
 
// Constraints:
// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        List<List<String>> list = new ArrayList<>();
        
        HashMap <String,List<String>> map =  new HashMap<>();
        
        for(int i=0;i<strs.length;i++){
            String word = strs[i];
            char[] letters = word.toCharArray();
            Arrays.sort(letters);
            
            String newword = new String(letters);
            
            if(map.containsKey(newword)){
                map.get(newword).add(word);
            }else{
                List<String> addwords = new ArrayList<>();
                addwords.add(word);
                map.put(newword,addwords);
            }
            
        }
        
        list.addAll(map.values());
               
        return list;
    }
}