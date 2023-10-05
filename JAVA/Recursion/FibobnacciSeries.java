import java.util.Scanner;

public class FibobnacciSeries {

    static int printFiboo(int num){
        if(num == 0){
         return 0;
        }

        if(num == 1){
            return 1;
        }

        int ans = printFiboo(num-1) + printFiboo(num -2);
        return ans;
     
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("enter the number upto which you want to print the fibonacci series");
        int number = sc.nextInt();
        sc.close();
       int num =  printFiboo(number);
        System.out.println(" the entered number term in the series is " + num);
    }
    
}
