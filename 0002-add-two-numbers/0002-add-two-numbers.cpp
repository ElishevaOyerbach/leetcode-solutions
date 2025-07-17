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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_list = new ListNode();
        ListNode* list_2 = new_list;
        int if_big_then_10 = 0;
        ListNode* temp = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + if_big_then_10;

            if (sum < 10) {
                temp = new ListNode(sum);
                if_big_then_10 = 0;
            } else {
                temp = new ListNode(sum - 10);
                if_big_then_10 = 1;
            }

            new_list->next = temp;
            new_list = new_list->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (if_big_then_10 == 1) {
            new_list->next = new ListNode(1);
        }

        return list_2->next;
    }
};