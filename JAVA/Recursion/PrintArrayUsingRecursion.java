public class PrintArrayUsingRecursion {
    static void printArr(int [] A , int index){
        int length = A.length;
        if(index >= length){
            return ;
        }
        System.out.print(" ");
        System.out.print(A[index] +" ");

        printArr(A, index+1);


    }
    public static void main(String[] args) {
        int [] arr = {1,2,3,5,7};
        int index = 0;
      
       printArr(arr, index);

    }
}
