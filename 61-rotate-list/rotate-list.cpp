class Solution {
public:
    int getlength(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void rotate(ListNode* &head, int k){
        if(!head || !head->next ){
            return ;
        }

        int n = getlength(head);
        k = k % n;

        if(k == 0) return;

        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }


        tail->next = head;

        int steps = n - k;
        ListNode* newTail = head;

        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = getlength(head);

        if(n == 0 || n == 1 ){
            return head;
        }
        if(k == 0) return head;

        rotate(head, k);

        return head;
    }
};