const LongestSubstring = (s) => {

    //sliding window approach
    if (!s) {
        return false;
    }
    let end = 0;
    let start = 0;
    let maxLength = 0;
    const uniqueSet = new Set();
    while (end < s.length) {
        if (!uniqueSet.has(s[end])) {
            uniqueSet.add(s[end]);
            end++;
            maxLength = Math.max(maxLength, uniqueSet.size);
            console.log(uniqueSet)
        } else {
            uniqueSet.delete(s[start]);
            console.log(uniqueSet)
            start++;
        }
    }
    console.log(uniqueSet)
    return maxLength;
}
let s = "abcabcdd";
console.log(LongestSubstring(s));