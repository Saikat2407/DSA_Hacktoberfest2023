package Array;

public class DutchFlag {
    public static void main(String[] args) {
        int[] arr = {0, 0, 2, 2, 1, 0, 2};
        flag(arr);
    }

    public static void flag(int[] arr) {
        int temp;
        int low = 0;
        int high = arr.length - 1;
        int mid = 0;

        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    temp = arr[mid];
                    arr[mid] = arr[low];
                    arr[low] = temp;
                    low++;
                    mid++;
                    break;

                case 1:
                    mid++;
                    break;
                case 2:
                    temp = arr[mid];
                    arr[mid] = arr[high];
                    arr[high] = temp;
                    high--;
                    break;
            }
        }
        for (int k : arr) {
            System.out.print(k + " ");
        }
    }
}
