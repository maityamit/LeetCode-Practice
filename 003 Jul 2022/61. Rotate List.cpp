class Solution {
public:
    ListNode* helper(ListNode* head){
        ListNode* temp=head;
        ListNode*p = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        p = temp->next;
        temp->next=NULL;
        p->next=head;
        head=p;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        int len=0;
        ListNode* ji = head;
        while(ji!=NULL){
            len++;
            ji=ji->next;
        }
        k=k%len;
        while(k--){
            head=helper(head);
        }
        return head;
    }
};
