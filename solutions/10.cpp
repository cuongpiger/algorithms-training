// O(max(m, n))

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

    vector<pair<int, int>> res;
    int n, m, x, y, sols[100010];
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; ++i) cin >> sols[i];
    for (int suit, j = 0, i = 0; i < m; ++i) {
        cin >> suit;

        while (j < n) {
            if (sols[j] - x <= suit && suit <= sols[j] + y) {
                res.push_back({j + 1, i + 1}); 
                j += 1;
                break;
            } else if (sols[j] - x > suit) {
                break;
            }

            j += 1;
        }

    }

    cout << res.size();
    for (int i = 0; i < res.size(); ++i) {
        cout << endl << res[i].first << " " << res[i].second;
    }

    return 0;
}