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
    int countNodes(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next) return NULL;
        int nodes = countNodes(head);
        ListNode* curr=head;
        if (n >= nodes) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int k = nodes - n - 1;
        while(k--){
            curr = curr -> next;
        }
        ListNode* curr1 = curr -> next;
        curr -> next = curr -> next -> next;
        delete curr1;
        return head;
    }
};