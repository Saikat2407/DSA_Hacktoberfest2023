import java.util.Random;
import java.util.Scanner;

public class GuessTheNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        int lowerBound = 1;
        int upperBound = 100;
        int numberToGuess = random.nextInt(upperBound - lowerBound + 1) + lowerBound;
        int attempts = 0;
        
        System.out.println("Welcome to the Guess the Number game!");
        System.out.println("I've selected a random number between 1 and 100.");
        
        while (true) {
            System.out.print("Enter your guess: ");
            int userGuess = scanner.nextInt();
            attempts++;
            
            if (userGuess < lowerBound || userGuess > upperBound) {
                System.out.println("Please enter a number between 1 and 100.");
            } else if (userGuess < numberToGuess) {
                System.out.println("Too low. Try again.");
            } else if (userGuess > numberToGuess) {
                System.out.println("Too high. Try again.");
            } else {
                System.out.println("Congratulations! You guessed the number " + numberToGuess + " in " + attempts + " attempts.");
                break;
            }
        }
        
        scanner.close();
    }
}
