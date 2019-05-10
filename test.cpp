#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A{0, 1, 2};
    const int n = A.size();
    unordered_set<int> ans(begin(A), end(A));
    cout << ans.size() << endl;
    return 0;
}