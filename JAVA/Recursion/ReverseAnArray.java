public class ReverseAnArray {
    static void reversedArr(int [] array , int start , int end ){
        if(start >= end ){
            return ;
        }

        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;

        reversedArr(array, start+1, end-1);

    }
    public static void main(String[] args) {
        int [] arr = {1,2,3,4,5};
        System.out.println("the array before reverse is ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        int i = 0;
        int j = arr.length-1;
        reversedArr(arr , i , j);
        System.out.println();
        System.out.println("the array after swap is ");
        for (int k : arr) {
            System.out.print(k + " ");
        }
    }
}
