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

    int n, k, a[100010], f[100010] = {0}, dst = 0;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0, i = 0; i < n; ++i) {
        dst += (f[a[i]] == 0);
        f[a[i]] += 1;

        while (dst >= k) {
            f[a[j]] -= 1;
            dst -= (f[a[j]] == 0);

            if (dst < k) {
                cout << j + 1 << " " << i + 1;
                return 0;
            }

            j += 1;
        }
    }

    cout << "-1 -1";

    return 0;
}