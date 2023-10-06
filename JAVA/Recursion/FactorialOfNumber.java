public class FactorialOfNumber {
    static int findFactorial(int n){
        if(n==0){
            return 1;
        }
         return n * findFactorial(n-1);
    }
    public static void main(String[] args) {
        int num  = 5;
        System.out.println("the factorial of natural  number is " + findFactorial(num));
    }
}
