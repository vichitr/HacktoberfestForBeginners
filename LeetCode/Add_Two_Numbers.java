/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode curr, dummy;
        int l1Digit, l2Digit, sum, carry;

        sum = 0;
        carry = 0;

        dummy = new ListNode(0);
        curr = dummy;

        while (l1 != null || l2 != null) {

            // get the digit or treat it as 0
            l1Digit = (l1 != null) ? l1.val : 0;
            l2Digit = (l2 != null) ? l2.val : 0;

            // calculate sum and carry
            sum = carry + l1Digit + l2Digit;
            carry = sum / 10;

            // assign the last digit of 'sum' and increment the 'curr' pointer
            curr.next = new ListNode(sum % 10);
            curr = curr.next;

            // in case l1 and l2 are not of the same length
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        // there might be a carry still left
        if (carry > 0) {
            curr.next = new ListNode(carry);
        }
        
        return dummy.next;
    }
}