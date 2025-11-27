import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class BogosortWithUserInput {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] array = new int[n];

        // Input array elements from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            array[i] = scanner.nextInt();
        }

        System.out.println("Unsorted Array: " + Arrays.toString(array);
        
        // Call the Bogosort algorithm to sort the array
        bogosort(array);
        
        // Display the sorted array
        System.out.println("Sorted Array: " + Arrays.toString(array));
    }

    // Bogosort algorithm
    public static void bogosort(int[] array) {
        // Continue until the array is sorted
        while (!isSorted(array)) {
            // Shuffle the array randomly
            shuffleArray(array);
        }
    }

    // Check if the array is sorted
    public static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            // If any element is out of order, the array is not sorted
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        // If the loop completes without finding an unsorted element, it's sorted
        return true;
    }

    // Shuffle the elements of the array randomly
    public static void shuffleArray(int[] array) {
        Random rand = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            // Generate a random index between 0 and i
            int index = rand.nextInt(i + 1);
            
            // Swap the elements at index i and the random index
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
}
