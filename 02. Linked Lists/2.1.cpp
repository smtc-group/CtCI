#include <bits/stdc++.h>
using namespace std;

// Time: O(n), Space: O(n)
void deleteDups(list<int>& mylist) {
    unordered_set<int> set;

    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        if (set.find(*it) != set.end())
            mylist.erase(it);
        else
            set.insert(*it);
    }
}

// Time: O(n^2), Space: O(1)
void deleteDups2(list<int>& mylist) {
    for (auto i = mylist.begin(); i != mylist.end(); i++) {
        for (auto j = next(i, 1); j != mylist.end(); j++) {
            if (*i == *j) {
                mylist.erase(j);
            }
        }
    }
}

void printList(list<int>& mylist) {
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it << " ";
    }
}

int main() {
    list<int> mylist{1, 3, 3, 4, 1, 3, 5};

    deleteDups(mylist);
    // deleteDups2(mylist);
    printList(mylist);

    return 0;
}