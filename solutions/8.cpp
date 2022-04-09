#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int l[100010], r[100010];

int main() {
    FAST_IO;
    // FILE_IO;

    int n, res = -1, lm = 1e9 + 10, rm = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        lm = min(l[i], lm);
        rm = max(r[i], rm);
    }

    for (int i = 1; i <= n; ++i) {
        if (l[i] == lm && r[i] == rm) {
            res = i;
            break;
        }
    }

    cout << res;

    return 0;
}