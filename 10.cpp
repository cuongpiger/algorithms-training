#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int cnt[110] = {0};

int main() {
    FAST_IO;
    // FILE_IO;

    vector<pair<int, int>> res;
    int n, m, x, y, sols[(int)1e9 + 10], suits[(int)1e9 + 10];
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; ++i) cin >> sols[i];
    for (int i = 0; i < m; ++i) cin >> suits[i];
    

    for (int i = 0, j = -1; i < n; ++i) {
        while (j < m) {
            j += 1;

            if (sols[i] - x <= suits[j] && suits[j] <= sols[i] + y) {
                res.app
            }
        }
    }
    return 0;
}