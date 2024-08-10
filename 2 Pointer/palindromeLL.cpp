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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int size(ListNode* head){
        int cnt = 1;
        while(head){
            cnt++;
            head = head->next;
        }  
        return cnt;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        int size_LL = size(head);
        ListNode* mid = head;
        for (int i = 0; i < size_LL / 2; i++) {
            mid = mid->next;
        }
        ListNode* reversedSecondHalf = reverse(mid);
        ListNode* temp1 = head;
        ListNode* temp2 = reversedSecondHalf;
        while (temp2) {
            if (temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};