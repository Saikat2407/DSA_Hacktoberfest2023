// Leetcode problem
// https://leetcode.com/problems/zigzag-conversion/

public class Zigzag_conversion {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s; // No need to convert if numRows is 1
        }
        
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }
        
        int direction = -1; // Initialize the direction to move (up or down)
        int currentRow = 0;
        
        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);
            
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction *= -1; // Change direction at the first and last rows
            }
            
            currentRow += direction;
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        
        return result.toString();
    }
    
}
