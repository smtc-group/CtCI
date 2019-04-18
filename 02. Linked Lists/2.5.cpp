#include <bits/stdc++.h>
#include "preprocessing.h"
using namespace std;

class Solution {
public:
    ListNode* addLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* l = &dummy;
        int carry = 0;

        while (carry || l1 || l2) {
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l->next = new ListNode(carry % 10);
            l = l->next;
            carry /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);  // [7, 1, 6]
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);  // [5, 9, 2]

        ListNode* ret = Solution().addLists(l1, l2);  // [2, 1, 9]

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
