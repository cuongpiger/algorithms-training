// O(n)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)


int main() {
    FAST_IO;
    // FILE_IO;

    int n, k, x, balls[110], b[110], w[110] = {0}, L = 0, res = 0;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) cin >> balls[i];

    b[L] = balls[0];
    w[L] = 1;
    for (int i = 1; i < n; ++i) {
        if (balls[i] == b[L]) {
            w[L] += 1;
        } else {
            L += 1;
            b[L] = balls[i];
            w[L] = 1;
        }
    }

    for (int k = 0; k <= L; ++k) {
        if (b[k] == x && w[k] == 2) {
            int l = k - 1, r = k + 1, s = w[k];

            while (l > -1 && r <= L && b[l] == b[r] && w[l] + w[r] > 2) {
                s += (w[l] + w[r]);
                l -= 1;
                r += 1;
            }

            res = max(res, s);
        }
    }

    cout << res;

    return 0;
}