class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* curr=head;
        int size=0;
        while(curr){
            size++;
            curr=curr->next;
        }

        int partionsize=size/k;
         curr=head;
        vector<ListNode*> ans;

        for(int i=0; i<k; i++){
            int realsize=partionsize;
            if(i<size%k) realsize++;
            if(realsize==0){
                ans.push_back(NULL);
                continue;
            }
            ans.push_back(curr);

            for(int j=0; j<realsize-1; j++){
                curr=curr->next;
            }
            ListNode* temp=curr;
            curr=curr->next;
            temp->next=NULL;

        }
       
        return ans;

        
    }
};