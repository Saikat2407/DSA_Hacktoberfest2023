import java.util.*;

public class size_of_largestbst {
 static class Node{
    int data;
    Node left;
    Node right;
    public Node(int data){
        this.data=data;
        this.left=this.right=null;
    }
 }
 static class Info{
    boolean isBST;
    int size;
    int min;
    int max;
    public Info(boolean isBST,int size,int min ,int max){
        this.isBST=isBST;
        this.size=size;
        this.max=max;
        this.min=min;
    }
 }
 public static int maxBST=0;
 public static Info largestBST(Node root){
     Info leftInfo=largestBST(root.left);
     Info rightInfo=largestBST(root.right);
     int size=leftInfo.size+rightInfo.size+1;
     int min=Math.min(root.data, Math.min(leftInfo.min, rightInfo.min));
     int max=Math.max(root.data, Math.max(leftInfo.max, rightInfo.max));
     if(root.data<=leftInfo.max||root.data>=rightInfo.min){
        return new Info(false, size, min, max);
     }
     if(leftInfo.isBST&&rightInfo.isBST){
        maxBST=Math.max(maxBST, size);
        new Info(true, size, min, max);
     }
     return new Info(false, size, min, max);
}
 
    public static void main(String[] args) {
        Node root=new Node(50);
        root.left=new Node(30);
        root.right=new Node(60);
        root.left.left=new Node(5);
        root.left.right=new Node(20);
        root.right.left=new Node(45);
        root.right.right=new Node(70);
        root.right.right.left=new Node(65);
        root.right.right.right=new Node(80);
        Info info=largestBST(root);
        System.out.println(maxBST);
    }
}
