#include <bits/stdc++.h>
using namespace std;

bool isUniqueChars(string str) {
    if (str.length() > 128) return false;

    bool* char_set = new bool[128];
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (char_set[val]) {  // Already found this char in string
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

bool isUniqueChars2(string str) {
    int checker = 0;
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if ((checker & (1 << val)) > 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

int main() {
    cout << "isUniqueChars(\"Apple\") = " << isUniqueChars("Apple") << endl;
    cout << "isUniqueChars(\"Cat\") = " << isUniqueChars("Cat") << endl;

    cout << "isUniqueChars2(\"Apple\") = " << isUniqueChars2("Apple") << endl;
    cout << "isUniqueChars2(\"Cat\") = " << isUniqueChars2("Cat") << endl;

    return 0;
}