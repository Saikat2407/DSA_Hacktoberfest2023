//Java Program to Count the Number of Digits in a Number.

import java.util.*;
class CountDigit {

    public static int countDigits(int n) {
		if(n == 0) return 1;

		//if a negative number is entered
		if(n < 0) n = -n;

        int res = 0;
		while(n != 0) {
			n = n/10;
			res++;
		}
		return res;
	}

	public static void main(String args[]) {
		// Your code goes here
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(); //input the number
		System.out.println("The number of digits in " + n + " are: " + countDigits(n));
	}
}
