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
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode*slow=head;
        ListNode*fast= head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode*mid= slow->next;
        slow->next= NULL;
        ListNode*left= sortList(head);
        ListNode*right= sortList(mid);
        return mergeSortListNode(left,right);
    }
    ListNode*mergeSortListNode(ListNode*l1, ListNode*l2){
        ListNode dummy(0);
        ListNode*curr= &dummy;
        while(l1!=NULL and l2!=NULL){
            if(l1->val<l2->val){
                curr->next= l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2= l2->next;
            }
            curr= curr->next;
        }
        if(l1!=NULL){
            curr->next= l1;
        }
        else{
            curr->next= l2;
        }
        return dummy.next;
    }
};
