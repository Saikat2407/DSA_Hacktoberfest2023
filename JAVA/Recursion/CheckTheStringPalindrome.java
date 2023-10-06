public class CheckTheStringPalindrome {
    static boolean checkPalindrome(String s, int start, int end) {
        if (start >= end) {
            return true; // Base case: If the characters are the same or we've reached the middle of the string, it's a palindrome.
        }

        if (s.charAt(start) != s.charAt(end)) {
            return false; // If characters don't match, it's not a palindrome.
        }

        return checkPalindrome(s, start + 1, end - 1); // Recurse for the inner substring.
    }

    public static void main(String[] args) {
        String str = "racing car";
        int i = 0;
        int j = str.length() - 1;
        boolean isPalindrome = checkPalindrome(str, i, j);
        
        if (isPalindrome) {
            System.out.println("The given string is a palindrome.");
        } else {
            System.out.println("The given string is not a palindrome.");
        }
    }
}
