class Solution {
public:
    int Length(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
        count++;
        temp = temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        int len =  Length(head);
        if(len<k || !head) return head;
        ListNode* dummy = new ListNode(10);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* prev = dummy;
        ListNode* nex = dummy;
        while(len >= k){
            curr = prev->next;
            nex = curr->next;
            for(int i = 1; i<k; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len = len-k;
        }
        return dummy->next;
    }
    ListNode* swapPairs(ListNode* head) {
    //METHOD 1:
    //    if(!head or !head->next) return head;
    //    ListNode* temp = head->next;
    //    head->next = swapPairs(temp->next);
    //    temp->next = head;
    //    return temp;
    
    //METHOD 2
    return reverseKGroup(head , 2);
    }
};