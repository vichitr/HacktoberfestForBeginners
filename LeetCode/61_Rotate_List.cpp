/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            /* if Linked List is empty or these is only one node, result will be that Linked
            List so returning head pointer.*/
            return head;
        }
        ListNode* a1=head;
        ListNode* a2= head; //two pointer variable a1, a2 of type ListNode, pointing to head.
        ListNode* forcount=head;
        int count=0;         //for counting the length of linked list.
        
        while(forcount!=nullptr){
            count++;
            forcount=forcount->next;
        }
        if(k>=count){
            k%=count; // if k is more than length of linkedlist we take modulo.
        }
        if(k==0){
            return head;
        }
        
        while(k){
            k--;
            a2=a2->next;  //a2 marching forward k steps.
        }
        
        while(a2->next!=nullptr){
            a2=a2->next;  //a2 starts from kth node ahead, loop till its next points to                               //null.
            a1=a1->next;  //a1 start from head pointer.
                          //so a1 will point to count-k th node from start or k
        }
        ListNode* newhead= a1->next;
        a1->next=nullptr;
        a2->next=head;
        return newhead;
    }
};
