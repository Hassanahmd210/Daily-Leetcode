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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;

        for (int i = 1; i < a; i++){
            p1 = p1->next;
        }

        ListNode* p3 = p1->next;

        for (int i = a; i <= b; i++) {
            p3 = p3->next;
        }

        p1->next = p2;

        while (p2->next) {
            p2 = p2->next;
        }
        
        p2->next = p3;

        return l1;
    }
};