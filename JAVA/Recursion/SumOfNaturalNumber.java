public class SumOfNaturalNumber {
    static int findSum(int n){
        if(n==0){
            return 0;
        }
         return n + findSum(n-1);
    }
    public static void main(String[] args) {
        int num  = 5;
        System.out.println("the sum of natural  number is" + findSum(num));

    }
}
