// O(n)

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int nA, nB, k, m, maxA, minB, x;
    
    cin >> nA >> nB >> k >> m;
    for (int i = 0; i < nA; ++i) {
        cin >> x;

        if (i == k - 1) maxA = x;
    }

    for (int i = 0; i < nB; ++i) {
        cin >> x;

        if (i == nB - m) minB = x;
    }

    cout << (maxA < minB ? "YES" : "NO");


    return 0;
}