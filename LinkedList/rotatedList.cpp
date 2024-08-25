class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }
        
        current->next = head;
        
        k = k % length;
        int stepsToNewHead = length - k;
        ListNode* newTail = head;
        
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};