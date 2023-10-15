package LeetCode.LinkList;

public class ReverseKGroup_25 extends LinkedList {
    public static void main(String[] args) {

    }

    public int size(ListNode head) {
        if(head == null){
            return 0;
        }

        if(head.next == null){
            return 1;
        }

        int count=0;

        while(head != null){
            count++;
            head = head.next;
        }

        return count;
    }

    public ListNode reverseKGroup(ListNode head, int k) {

        if(head == null){
            return null;
        }

        if(head.next == null){
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;
        ListNode nex = null;
        int count = 0;

        while (curr!=null && count<k){
            nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
            count++;
        }

        if(nex!=null && size(nex)>=k){
            head.next = reverseKGroup(nex, k);
        } else {
            head.next = nex;
        }

        return prev;
    }
}
