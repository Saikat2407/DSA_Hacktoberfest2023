import java.util.HashMap;

public class CountOccurance {
    public static void main(String[] args) {
        int[] myArray = {1, 2, 3, 1, 2, 1, 4, 5, 4, 3};
        HashMap<Integer, Integer> occurrenceCount = countOccurrences(myArray);
        System.out.println(occurrenceCount);
    }

    public static HashMap<Integer, Integer> countOccurrences(int[] arr) {
        HashMap<Integer, Integer> occurrenceCount = new HashMap<>();

        for (int element : arr) {
            occurrenceCount.put(element, occurrenceCount.getOrDefault(element, 0) + 1);
        }

        return occurrenceCount;
    }
}
