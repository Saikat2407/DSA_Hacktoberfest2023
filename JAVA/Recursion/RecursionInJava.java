import java.util.*;
public class RecursionInJava{

     static int factorial(int number){
            if(number == 0 || number == 1) return 1;
            return number*factorial(number -1);
        }
    public static void main(String [] args){
        // This is the first lecture of recusrion  of the playlist of  love babbr

       
   System.out.println(" Recursion in java  ");
   Scanner sc = new Scanner(System.in);
   System.out.println(" enter the number : ");
   int num = sc.nextInt();
   sc.close();
   int ans = factorial(num);
   System.out.println(" the factorial of the number is :  " + ans);
    }
}