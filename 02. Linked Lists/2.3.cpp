#include <bits/stdc++.h>
using namespace std;

bool deleteNode(list<int>& mylist, list<int>::iterator it) {
    if (next(it, 1) == mylist.end()) {
        return false;
    }

    mylist.erase(it);
    return true;
}

void printList(list<int>& mylist) {
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it << " ";
    }
}

int main() {
    list<int> mylist{1, 2, 3, 4, 5, 6, 7};
    auto it = next(mylist.begin(), 3);

    cout << deleteNode(mylist, it) << endl;

    printList(mylist);

    return 0;
}