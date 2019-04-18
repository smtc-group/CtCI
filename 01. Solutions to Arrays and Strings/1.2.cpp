#include <bits/stdc++.h>
using namespace std;

string sort(string s) {
    char char_array[s.length() + 1];
    strcpy(char_array, s.c_str());
    sort(char_array, char_array + strlen(char_array));
    return string(char_array);
}

bool permutation(string s, string t) {
    if (s.length() != t.length()) return false;
    return sort(s).compare(sort(t));
}

int main() {
    if (!permutation("bacfed", "abdefc"))
        cout << "\"bacfed\" is a permutation of \"abdefc\"" << endl;
    else
        cout << "\"bacfed\" is not a permutation of \"abdefc\"" << endl;

    return 0;
}
