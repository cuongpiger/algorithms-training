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

    int n, iten[100010], freq[100010] = {0}, res = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> iten[i];
    }

    int cnt = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        if (freq[iten[j]] == 0) {
            cnt += 1;
        }

        freq[iten[j]] += 1;

        while (cnt > 2) {
            freq[iten[i]] -= 1;
            if (freq[iten[i]] == 0) cnt -= 1;
            i += 1;
        }

        res = max(res, j - i + 1);
    }

    cout << res;

    return 0;
}