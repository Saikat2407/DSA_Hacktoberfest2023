import java.util.HashMap;
import java.util.Scanner;

public class SpellChecker {
    public static void main(String[] args) {
        // Create a HashMap to store the dictionary of valid words
        HashMap<String, Boolean> dictionary = new HashMap<>();
        
        // Load the dictionary with sample words (you can load it from a file)
        dictionary.put("apple", true);
        dictionary.put("banana", true);
        dictionary.put("cherry", true);
        dictionary.put("date", true);
        dictionary.put("fig", true);
        
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter text to check for spelling errors: ");
        String text = scanner.nextLine();
        
        String[] words = text.split("\\s+"); // Split input text into words
        
        System.out.println("Spelling Errors:");
        for (String word : words) {
            // Remove punctuation and convert to lowercase for comparison
            word = word.replaceAll("[^a-zA-Z]", "").toLowerCase();
            
            // Check if the word is in the dictionary
            if (!dictionary.containsKey(word)) {
                System.out.println(word);
            }
        }
    }
}
