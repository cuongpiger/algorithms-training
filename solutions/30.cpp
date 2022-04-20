// O(t*n) with t is the number of test cases and n is the number of cards

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <set>
#include <stack>
#include <numeric>
#include <regex>
#include <queue>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

const int MAX = 60;
string disCards[60];

inline string join(const int &n, const string &delim) {
    return accumulate(disCards, disCards + (sizeof(disCards)/sizeof(disCards[0])) / MAX * n, string(), [&delim](string &x, string &y) {
        return x.empty() ? y : x + delim + y;
    });
}
 
inline pair<string, string> solve(const int &n) {
    queue<string> decks;
    for (int i = 1; i <= n; ++i) decks.push(to_string(i));

    int i = 0;
    while (decks.size() > 1) {
        disCards[i++] = decks.front();
        decks.pop();

        decks.push(decks.front());
        decks.pop();
    }

    string f = join(i, (string) ", ");
    f = f.empty() ? "" : ' ' + f;

    return pair<string, string>(f, ' ' + decks.front());
}

int main() {
    FAST_IO;
    // FILE_IO;

    int n;

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        pair<string, string> res = solve(n);
        cout << "Discarded cards:" << res.first << endl;
        cout << "Remaining card:" << res.second << endl;
    }

    return 0;
}