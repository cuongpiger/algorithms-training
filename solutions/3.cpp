#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int cost = 0;
    string s = "";
    char cur = 'a';

    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        cost += min(abs(cur - s[i]), abs(26 - abs(cur - s[i])));
        cur = s[i];
    }

    cout << cost;

    return 0;
}