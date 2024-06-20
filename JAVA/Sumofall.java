import java.util.Scanner;

public class Sumofall {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int sum = 0;

        while (true) {
            String input = in.next();

            if (input.equals("x")) {
                break;
            }
            else {
                int num = Integer.parseInt(input);
                sum += num;
            }
        }

        System.out.println("Sum: " + sum);
    }
}
