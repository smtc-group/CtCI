#include <bits/stdc++.h>
#include "preprocessing.h"
using namespace std;

class Solution {
public:
    ListNode* findBeginning(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find meeting point. This will be LOOP_SIZE - k steps into the linked
        // list.
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (&slow->val == &fast->val) {
                break;
            }
        }

        // Error check - no meeting point, and therefore no loop
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Move slow to Head. Keep fast at Meeting Point. Each are k steps from
        // the Loop Start. If they move at the same pace, they must meet at Loop
        // Start.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both now point to the start of the loop.
        return fast;
    }
};

int main() {
    ListNode* l = new ListNode(0);
    ListNode* head = l;

    // 3 nodes before loop + 8-nodes loop
    for (int i = 1; i < 11; i++) {
        l->next = new ListNode(i);
        l = l->next;
    }
    l->next = head->next->next->next;
    cout << l->val << head->next->next->next->val << endl;

    ListNode* looped = Solution().findBeginning(head);  // 1 (true)

    cout << looped->val << endl;
    return 0;
}
