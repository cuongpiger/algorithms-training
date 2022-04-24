// O(t*m) with t is number of test case and m is the number of cars

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

#define id first
#define vl second

int main() {
    FAST_IO;
    // FILE_IO;

    int N, n, t, m, x, fb, ft, noc, res[10010]; cin >> N;
    string b;
    bool isMove;

    while (N--) {
        cin >> n >> t >> m;
        queue<pair<int, int>> q[2];
        for (int i = 0; i < m; ++i) {
            cin >> x >> b;
            q[(b == "right")].push({i, x});
        }

        ft = 0, fb = 0;
        while (q[0].empty() + q[1].empty() != 2) {
            isMove = false;
            noc = 0;

            while (!q[fb].empty() && noc++ < n && q[fb].front().vl <= ft) {
                res[q[fb].front().id] = ft + t;
                q[fb].pop();
                isMove = true;
            }

            if (isMove) {
                ft += t;
                fb = 1 - fb;
                continue;
            }

            if (q[0].empty() + q[1].empty() == 0) {
                if (q[fb].front().vl <= q[1 - fb].front().vl) {
                    ft = max(ft, q[fb].front().vl);
                } else {
                    ft = max(ft, q[1 - fb].front().vl) + t;
                    fb = 1 - fb;
                }
            } else {
                if (!q[fb].empty()) {
                    ft = max(ft, q[fb].front().vl);
                } else if (!q[1 - fb].empty()) {
                    ft = max(ft, q[1 - fb].front().vl) + t;
                    fb = 1 - fb;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            cout << res[i] << endl;
        }

        if (N) cout << endl;
    }


    return 0;
}
