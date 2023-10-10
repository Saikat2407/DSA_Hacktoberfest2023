
import java.util.Scanner;
public class Binary_Search {
    public static int Binary_Search(int arr[], int key){
        int start=0,end=arr.length-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==key){
                return mid;
            }
            if(arr[mid]<key){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter The Size Of The Array:- ");
        int size=sc.nextInt();
        int arr[]=new int[size];
        for(int i=0;i<size;i++){
            System.out.print("Enter Arr["+i+"]:- ");
            int x=sc.nextInt();
            arr[i]=x;
        }
        System.out.println("The Array Is:- ");
        for(int i=0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print("\nEnter The String You Want To Search:- ");
        int key=sc.nextInt();
        int x=Binary_Search(arr, key);
        if(x < 0){
            System.out.print("\nYour Given Key Is Not Present In The Array");
        }
        else{
            System.out.println("Your Key Is Present In The Array At The Position:- "+x);
        }
    }

}
