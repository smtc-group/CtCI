#include <bits/stdc++.h>
using namespace std;

list<int>::iterator printKthToLast(list<int>& mylist, int k) {
    auto p1 = mylist.begin();
    auto p2 = mylist.begin();

    while (k--) p1++;

    // cout << *p1 << endl;

    while (p1 != mylist.end()) {
        p1++;
        p2++;
    }

    auto it = p2;

    for (; p2 != mylist.end(); p2++) {
        cout << *p2 << " ";
    }

    return it;
}

int main() {
    list<int> mylist{1, 2, 3, 4, 5, 6, 7};

    auto it = printKthToLast(mylist, 3);

    return 0;
}