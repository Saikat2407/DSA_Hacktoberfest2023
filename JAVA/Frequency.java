import java.util.Scanner;

public class Frequency {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter your number : ");
        String word = in.next();
        int n=0;
        for (int i=0;i<word.length();i++){
            if(word.charAt(i) == '7'){
                n+=1;
            }
        }
        System.out.println("Frequency of 7 in  " + word + " is : " + n);
    }
}
/* we can also generate last digit by using modulo operator and compare each time */