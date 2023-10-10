/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 Example 1:
 Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 Output: 6
 Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

 Example 2:

 Input: height = [4,2,0,3,2,5]
 Output: 9
 

 Constraints:

 n == height.length
 1 <= n <= 2 * 104
 0 <= height[i] <= 105
 */

 import java.util.Scanner;
 class Trapping_Rainwater{
    public static int Trap(int arr[]){
        //left max Auxilary Array
        int n=arr.length;
        int leftMax[]=new int[n];
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftMax[i]=Math.max(arr[i], leftMax[i-1]);
        }
        //right max Auxilary Array
        int rightMax[]=new int[n];
        rightMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=Math.max(arr[i], rightMax[i+1]);
        }
        //main loop
        int sum=0;
        for(int i=0;i<n;i++){
            int water_level=Math.min(rightMax[i], leftMax[i]);
            sum+=water_level-arr[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        int arr[]={4,2,0,6,3,2,5};
        System.out.println("Rainwater Trapped:- "+Trap(arr));
    }
 }