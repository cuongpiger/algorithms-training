// O(t*n) with t is number of test cases and n is length of expression

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



int main() {
    FAST_IO;
    // FILE_IO;

    int p, c, x, cs = 1, f;
    char C;

    while (true) {
        cin >> p >> c; if (p + c == 0) break;
        queue<int> q;

        for (int i = 1; i <= min(p, c); ++i) q.push(i);
        
        cout << "Case " << cs++ << ":\n";
        while (c--) {
            cin >> C;
            if (C == 'N') {
                f = q.front();
                cout << q.front() << endl;
                q.push(q.front());
                q.pop();

            } else {
                cin >> x;
                queue<int> tq;
                tq.push(x);

                while (!q.empty()) {
                    f = q.front();

                    if (f != x) tq.push(f);
                    q.pop();
                }

                q.swap(tq);
            }
        }
    }

    return 0;
}