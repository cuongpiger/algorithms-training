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

    int n, t, res = 0, s = 0, books[100010];

    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }

    for (int j = 0, i = 0; i < n; ++i) {
        s += books[i];

        while (s > t) {
            s -= books[j++];
        }

        res = max(res, i - j + 1);
    }

    cout << res;

    return 0;
}