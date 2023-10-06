public class MaxiandMiniOfAnArray {


  // to find the maximum of the array 
   static void findMax(int [] arr ,int index , int max){
    int i = arr.length;
    if(index >= i){
      System.out.println("The maximum is " + max);
        return;
    }

     if(arr[index]>max){
        max=arr[index];
     }
     
    findMax(arr, index+1, max);
   }

    static void findMin(int [] arr ,int index , int min){
    int i = arr.length;

    if(index >= i){
      System.out.println("The minimum  is " + min);
        return;
    }

     if(arr[index]<min){
        min=arr[index];
     }
     
    findMin(arr, index+1, min);
   }
   
    public static void main(String[] args) {
        int [] arr = {1,2,3,5,7};
        int index = 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
      
      findMax(arr, index , max);
      findMin(arr , index , min);
   

    }
}
