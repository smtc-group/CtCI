#include <bits/stdc++.h>
#include "preprocessing.h"
using namespace std;

class Solution {
public:
    // Pass in the head of the linked list and the value to partition around
    ListNode* partition(ListNode* node, int x) {
        ListNode* beforeHead = NULL;
        ListNode* beforeTail = NULL;
        ListNode* afterHead = NULL;
        ListNode* afterTail = NULL;

        while (node != NULL) {
            ListNode* next = node->next;
            node->next = NULL;
            if (node->val < x) {
                // Insert node into end of before list
                if (beforeHead == NULL) {
                    beforeHead = node;
                    beforeTail = node;
                } else {
                    beforeTail->next = node;
                    beforeTail = node;
                }
            } else {
                // Insert node into end of after list
                if (afterHead == NULL) {
                    afterHead = node;
                    afterTail = node;
                } else {
                    afterTail->next = node;
                    afterTail = node;
                }
            }
            node = next;
        }

        if (beforeHead == NULL) {
            return afterHead;
        }

        // Merge before list and after list
        beforeTail->next = afterHead;
        return beforeHead;
    }

    ListNode* partition2(ListNode* node, int x) {
        ListNode* head = node;
        ListNode* tail = node;

        while (node != NULL) {
            ListNode* next = node->next;
            if (node->val < x) {
                // Insert node at head
                node->next = head;
                head = node;
            } else {
                // Insert node at tail
                tail->next = node;
                tail = node;
            }
            node = next;
        }
        tail->next = NULL;

        // The head has changed, so we need to return it to the user
        return head;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);  // [3, 5, 8, 5, 10, 2, 1]
        getline(cin, line);
        int n = stringToInteger(line);  // 5

        ListNode* ret = Solution().partition(head, n);
        // [3, 2, 1, 5, 8, 5, 10]

        ListNode* ret = Solution().partition2(head, n);
        // [1, 2, 3, 5, 8, 5, 10]

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
