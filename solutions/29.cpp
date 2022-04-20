// O(t*n) with t is number of test cases and n is length of expression

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

inline string solve(string &s) {
    stack<char> straw;
    string res = "";
    char top;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        } else if (s[i] == ')') {
            res += straw.top(); straw.pop();
        } else if (s[i] != '(') 
            straw.push(s[i]);
    }

    while (!straw.empty()) {
        res += straw.top(); straw.pop();
    }

    return res;
}

int main() {
    FAST_IO;
    // FILE_IO;

    int n;
    string s;
    stack<char> straw;

    cin >> n;
    while (n--) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}