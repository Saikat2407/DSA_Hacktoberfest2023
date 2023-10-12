/*
  21. Merge Two Sorted Lists
 You are given the heads of two sorted linked lists list1 and list2.

 Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

 Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

The solution is to use a tail pointer and the concept of merge function of merge sort.
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        if(list1==null)
            return list2;
        if(list2==null)
           return list1;
        ListNode a=list1,b=list2;
        ListNode tail=null,result=null;
        if(list1.val<=list2.val)
        {
            result=tail=a;
            a=a.next;
        }
        else
        {
            result=tail=b;
            b=b.next;
        }
        while(a!=null&&b!=null)
        {
            if(a.val<=b.val)
            {
                tail.next=a;
                tail=tail.next;
                a=a.next;
            }
            else
            {
                tail.next=b;
                tail=tail.next;
                b=b.next;
            }
        }
        if(a!=null)
         tail.next=a;
        else
         tail.next=b;
        return result;
    }
}
