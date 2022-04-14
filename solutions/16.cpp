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

    int n, m, p[3010], pp[3010], noSolved = 0;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> pp[i];
    }

    for (int j = 0, i = 0; i < n; ++i) {
        while (pp[j] < p[i] && j < m) j += 1;

        if (pp[j] >= p[i] && j < m) {
            noSolved += 1;
            j += 1;
        }
    }

    cout << n - noSolved;

    return 0;
}