#include <bits/stdc++.h>
#include "preprocessing.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* reversed = reverseAndClone(head);
        return isEqual(head, reversed);
    }

    ListNode* reverseAndClone(ListNode* node) {
        ListNode* head = NULL;
        while (node != NULL) {
            ListNode* n = new ListNode(node->val);
            n->next = head;
            head = n;
            node = node->next;
        }
        return head;
    }

    bool isEqual(ListNode* l1, ListNode* l2) {
        while (l1 != NULL && l2 != NULL) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1 == NULL && l2 == NULL;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l = stringToListNode(line);  // [0, 1, 2, 1, 0]

        bool ret = Solution().isPalindrome(l);  // 1

        cout << ret << endl;
    }
    return 0;
}
