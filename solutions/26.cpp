// O(n * length(s))

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

inline int solve(string &s) {
    int res = 0;

    for (int sm = 0, l = 0, i = 0; i < s.size(); ++i) {
        sm += s[i] == '<';
        sm -= s[i] == '>';

        if (sm == 0) res = i + 1;
        else if (sm < 0) break;
    }

    return res;
}


int main() {
    FAST_IO;
    // FILE_IO;

    int n; cin >> n;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}